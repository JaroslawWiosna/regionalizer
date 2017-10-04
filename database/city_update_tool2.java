package cities_updater_tool;

/**
 * @brief add coordinates to the rest of cities data
 * 
 * @condition_on_start webpage we use http://astronomia.zagan.pl/art/wspolrzedne.html must exist 
 * 					   and contains useful for this method informations
 * @condition_on_start file we use  cities_data_pre_parsed.txt that is database of cities names, area 
 * 					   and population must exists(otherwise we will get an error about it)
 * 
 * @way_of_working_step_1 takes the file and looks up on the webpage for matching city
 * @way_of_working_step_2 if it finds the matching pair, it adds combined information from 
 * 						  both sources to new file cities_data.txt. If it reach the end of the
 * 						  list of cities on the webpage with no pair it simply looks up for
 * 						  another city ignoring the previous one.			
 * 
 * @authors Wojciech Mielczarek
 * @authors Jaroslaw Wiosna
 * 
 * @todo TODOs are in city_updater_tool todo
 * 
 * @condition_on_stop creates final file cities_data.txt with all cities that he found the coordinates for on 
 * 					  the given webpage
 */

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.BufferedReader;
import java.io.File;
import java.io.InputStreamReader;
import java.net.URL; 
import java.net.URLConnection;
import java.util.Scanner;


public class city_update_tool2 {
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
						String arg_list[]=web_page_inputLine.split(" ");
						int coordinate_numbers=0;
						//if(web_page_inputLine.contains("Alwernia"))for(String element : arg_list)System.out.print(element); //left in case of error investigation
						for(String element : arg_list){
							if(element.contains("0")||element.contains("1")||element.contains("2")
									||element.contains("3")||element.contains("4")||element.contains("5")
									||element.contains("6")||element.contains("8")||element.contains("9")){
								switch(coordinate_numbers){
								case 0: {coordinates+=element+city_argument_splitter;break;}
								case 1: {
									if(element.contains("</PRE>")){String clear_element[]=element.split("</PRE>");
									coordinates+=clear_element[0];break;}
									else {coordinates+=element;break;}
								}
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
