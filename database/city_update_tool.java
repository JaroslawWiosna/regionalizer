package cities_updater_tool;

/**
 * @brief creates database of cities in Poland with their name, area and population number
 * 
 * @condition_on_start web-page we use https://pl.wikipedia.org/wiki/Miasta_w_Polsce_(statystyki) must exist 
 * 					   and contains useful for this method informations
 * 
 * @way_of_working Open the web-page and adds the cities from the web-page to the file.  		
 * 				   It does that by cutting the needed values from the web html.
 * @authors Wojciech Mielczarek
 * @authors Jaroslaw Wiosna
 * 
 * @todo TODOs are in city_updater_tool todo
 * 
 * @condition_on_stop creates final file cities_data_pre_parsed.txt with all cities that he founds the coordinates for, 
 * 					  on the given web-page
 */

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.BufferedReader; 
import java.io.InputStreamReader;
import java.net.URL; 
import java.net.URLConnection;


// not working so far
public class city_update_tool {
	public static String cutTheNameFromString(int location_of_the_city_name_in_table,String... list){
		String list2[]=list[location_of_the_city_name_in_table].split("<");
		String city_name=list2[0];
		return city_name;
	}

	public static void main(String[] args) {
		String city_argument_splitter="|";
		try {
			URL data = new URL("https://pl.wikipedia.org/wiki/Miasta_w_Polsce_(statystyki)");
			URLConnection connection = data.openConnection();
			BufferedReader web_data = new BufferedReader(new InputStreamReader(connection.getInputStream(), "UTF-8"));
			String inputLine;
			int linecount=0;
			PrintWriter Pre_parsed_database = new PrintWriter("cities_data_pre_parsed.txt");
			boolean start_writing=false;
			String writeToFile="";
			while ((inputLine = web_data.readLine()) != null) { 
				if(inputLine.contains("Liczba ludno")||inputLine.contains("<h2><span id="))start_writing=false;      
				if(inputLine.contains("<b>")&&inputLine.contains("</a></b></td>")){start_writing=true;linecount=0;} 
				if(start_writing){
					linecount++;
					if(linecount==2||linecount==3)continue;
				}           
				if(start_writing&&(inputLine.contains("title=")||inputLine.contains("tabela-liczba"))){
					String list[]=inputLine.split(">");
					//nazwa miasta
					if(linecount==1){
						if(inputLine.contains("<b>")&&inputLine.contains("<i>")){ writeToFile+=cutTheNameFromString(4,list)+city_argument_splitter;}
						else if(inputLine.contains("<b>")){writeToFile+=cutTheNameFromString(3,list)+city_argument_splitter;}
						else {writeToFile+=cutTheNameFromString(2,list)+city_argument_splitter;}
					}
					if(linecount==4||linecount==5){ 
						String list2[]=list[1].split("<");
						//area
						if(linecount==4)
							writeToFile+=(list2[0]+city_argument_splitter);
						//liczba mieszkancow
						else if(linecount==5){
							String list3[]=list2[0].split("&");
							String list4[]=list2[0].split(";");
							if(list2[0].contains(";")){
								String list5[]=list3[1].split(";");
								Integer liczbaludnosc=0;
								if(list4.length==2)liczbaludnosc = Integer.parseInt(list3[0])*1000+
										Integer.parseInt(list4[1]);
								if(list4.length==3)liczbaludnosc = Integer.parseInt(list3[0])*1000000+
										1000*Integer.parseInt(list5[1])+Integer.parseInt(list4[2]);
								writeToFile+=(liczbaludnosc.toString());
							} 
							else writeToFile+=(list2[0]);
							Pre_parsed_database.println(writeToFile);
							writeToFile="";}
					}
				}
				if(linecount==8){linecount=0;
				}

			}
			Pre_parsed_database.close();
			web_data.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
