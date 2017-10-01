package cities_updater_tool;

/*
 * @authors Wojciech Mielczarek
 * @authors Jaroslaw Wiosna
 * gets cities list with name, population, area
 */

import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.BufferedReader; 
import java.io.InputStreamReader;
import java.net.URL; 
import java.net.URLConnection;

// not working so far
public class city_update_tool {
    public static void main(String[] args) {
        try {
            URL data = new URL("https://pl.wikipedia.org/wiki/Miasta_w_Polsce_(statystyki)");
            URLConnection connection = data.openConnection();
            BufferedReader web_data = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            String inputLine;
            int linecount=0;
            PrintWriter zapis = new PrintWriter("cities_data.txt");
            boolean start_writing=false;
            while ((inputLine = web_data.readLine()) != null) {  
            	if(start_writing)linecount++;
            	if(linecount>1&&linecount<4)continue;
            	if(start_writing)System.out.println(inputLine);
                if(inputLine.contains("Edytuj sekcj"))start_writing=false;
                if(start_writing&&(inputLine.contains("title=")||inputLine.contains("tabela-liczba"))){
					switch(linecount){
						case 1:
	                	String line[] = inputLine.split(">");
						String line2[] = line[1].split("<");
	                	zapis.write(line2[0]+" ");
	                	break;
						case 4:
	                	String line3[] = inputLine.split(">");
						String line4[] = line3[1].split("<");
	                	zapis.write(line4[0]+" ");
	                	break;
						case 5:
						String line5[] = inputLine.split(">");
						String line6[] = line5[1].split("<");
		                zapis.write(line6[0]+" ");
		                break;
						case 6:
						String line7[] = inputLine.split(">");
						String line8[] = line7[1].split("<");
		                zapis.write(line8[0]+" ");
						zapis.println(" ");
		                break;
					}
                }
                if(linecount==6)linecount=0;
                if(inputLine.contains("zaludnienia"))start_writing=true;
            }
            zapis.close();
            web_data.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
