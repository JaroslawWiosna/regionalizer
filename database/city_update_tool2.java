package cities_updater_tool;

/**
 * @brief add coordinates to the rest of cities data
 * 
 * @condition_on_start web-page we use http://astronomia.zagan.pl/art/wspolrzedne.html must exist 
 * 					   and contains useful for this method informations
 * @condition_on_start file we use  cities_data_pre_parsed.txt that is database of cities names, area 
 * 					   and population must exists(otherwise we will get an error about it)
 * 
 * @way_of_working_step_1 takes the file and looks up on the web-page for matching city
 * @way_of_working_step_2 if it finds the matching pair, it adds combined information from 
 * 						  both sources to new file cities_data.txt. If it reach the end of the
 * 						  list of cities on the web-page with no pair it simply looks up for
 * 						  another city ignoring the previous one.
 * @way_of_working_step_3 for each pair it also parse coordinates removing from them direction
 * 						  like "E" and also changes in them minutes to decimal part of degrees 	
 * 
 * @authors Wojciech Mielczarek
 * @authors Jaroslaw Wiosna
 * 
 * @todo TODOs are in city_updater_tool todo
 * 
 * @condition_on_stop creates final file cities_data.txt with all cities that he found the coordinates for on 
 * 					  the given web-page
 */

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.net.URL; 
import java.net.URLConnection;
import java.util.Scanner;


public class city_update_tool2 {
	//takes coordinates like 22°15'E, removes direction and creates decimal part of degrees from minutes
	public static String remove_direction_and_change_to_decimal(String coordinates){
		final int calculation_accuracy=4;
		//")" in case when we have (county)22°15'E to remove (county)
		if(coordinates.contains(")")){
			String clear_element[]=coordinates.split("\\)");
			coordinates=clear_element[1];
		}
		if(coordinates.contains("</PRE>")){
			String clear_element[]=coordinates.split("</PRE>");
			coordinates=clear_element[0];
		}
		String list[]=coordinates.split("°");
		String list2[]=list[1].split("'");
		//list2[1] - contains direction -information for future improvement like other countries
		//here we change degree+minutes into degree with minutes as decimal part of degrees
		Double decimal_coordinates = Double.parseDouble(list[0])+ Double.parseDouble(list2[0])/60;
		decimal_coordinates = BigDecimal.valueOf(decimal_coordinates).setScale(calculation_accuracy, RoundingMode.HALF_UP).doubleValue();
		String final_coordinates=decimal_coordinates.toString();
		return final_coordinates;
	}

	public static void main(String[] args) {
		String city_argument_splitter="|";
		try {
			URL cities_cooridnates = new URL("http://astronomia.zagan.pl/art/wspolrzedne.html");
			URLConnection connection = cities_cooridnates.openConnection();
			BufferedReader web_data = new BufferedReader(new InputStreamReader(connection.getInputStream(), "iso-8859-2"));
			String city_file_inputLine, web_page_inputLine;
			File cities_data_pre_parsed;
			Scanner read = null;
			try {
				cities_data_pre_parsed = new File("cities_data_pre_parsed.txt");
				read = new Scanner(cities_data_pre_parsed);
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
			PrintWriter cities_data = new PrintWriter("cities_data.txt");
			while (read.hasNextLine()) {
				city_file_inputLine = read.nextLine();
				String coordinates="";
				String city_args[]=	city_file_inputLine.split(city_argument_splitter);
				boolean element_found=false;

				while (((web_page_inputLine = web_data.readLine()) != null)) { 
					if(web_page_inputLine.contains("META"))continue;
					if(web_page_inputLine.contains(city_args[0])){
						System.out.println(web_page_inputLine);
						String arg_list[]=web_page_inputLine.split(" ");
						int coordinate_numbers=0;
						//if(web_page_inputLine.contains("Alwernia"))for(String element : arg_list)System.out.print(element); //left in case of error investigation
						for(String element : arg_list){
							if(element.contains("0")||element.contains("1")||element.contains("2")
									||element.contains("3")||element.contains("4")||element.contains("5")
									||element.contains("6")||element.contains("8")||element.contains("9")){
								element= remove_direction_and_change_to_decimal(element);
								switch(coordinate_numbers){
								case 0: {coordinates+=element+city_argument_splitter;break;}
								case 1: {coordinates+=element;break;}
								}
								coordinate_numbers++;
							}
						}
						element_found=true;
					}
					if(element_found) break;
				}
				if(coordinates!="")cities_data.println(city_file_inputLine+city_argument_splitter+coordinates);
				coordinates="";
			}
			cities_data.close();
			web_data.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
