 
package cities_updater_tool;

/*
 * @authors Wojciech Mielczarek
 * @authors Jaroslaw Wiosna
 * fix the list of cities with missing coordinates
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
		try {
			URL cities_cooridnates = new URL("http://astronomia.zagan.pl/art/wspolrzedne.html");
			URLConnection connection = cities_cooridnates.openConnection();
			BufferedReader web_data = new BufferedReader(new InputStreamReader(connection.getInputStream()));
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
				String city_args[]=	city_file_inputLine.split("-");	
				boolean element_found=false;
				while (((web_page_inputLine = web_data.readLine()) != null)) {  

					if(web_page_inputLine.contains(city_args[0])){

						String arg_list[]=web_page_inputLine.split(" ");
						int coordinate_numbers=0;
					//	for(String element : arg_list)System.out.print(element);
						for(String element : arg_list){
							if(element.contains("0")||element.contains("1")||element.contains("2")
									||element.contains("3")||element.contains("4")||element.contains("5")
									||element.contains("6")||element.contains("8")||element.contains("9")){
								switch(coordinate_numbers){
								case 0: {coordinates+=element+"-";break;}
								case 1: {coordinates+=element;break;}
								}
								coordinate_numbers++;
							}
						}
						element_found=true;
					}
					if(element_found) break;
				}
				cities_data.println(city_file_inputLine+"-"+coordinates);
			}
			cities_data.close();
			web_data.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
