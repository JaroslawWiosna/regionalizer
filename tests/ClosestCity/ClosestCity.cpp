/**
 * @file databaseReader.cpp
 *
 * @author Jaroslaw Wiosna
 * @author Wojciech Mielczarek
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "ClosestCity.hpp"
#include "DatabaseReader.hpp"
#include <algorithm>
#include <cmath>
#include <gtest/gtest.h>
bool findCity(std::vector <City> vec, const std::string &city_name){
    for(auto it = vec.begin();it!=vec.end();++it){
        if(it->getName()==city_name) return true;
    }
    return false;
}

TEST(ClosestCity, ClassFunctionsTests) {

    //testing removeCitiesInVectorThatAreSmallerThanMe
    //For Warsaw we should have only one city - Warsaw
    //For others we should get more cities
    //TODO:vector pobierany z pliku moc 10 cities databaseReaderem.
    std::string path = "../../../database/Poland-Cities010-Top10-mock.txt";
    std::vector <City> vec = DatabaseReader::readCitiesFromFile(path);
    
    std::string CityNames[]={"Warsaw","Lodz","Szczecin", "Katowice", "Poznan","Krakow"};
    ClosestCity::removeCitiesInVectorThatAreSmallerThanMe(vec,CityNames[0]);
    ASSERT_EQ(1, vec.size()) << "We should erase cities smaller than Warsaw and therefore have just one city in vector but we have: " << vec.size() << " of them";
    ASSERT_TRUE(findCity(vec,CityNames[0])) << "We should have one " << CityNames[0] << " but we found" << findCity(vec,CityNames[0]);
    ASSERT_FALSE(findCity(vec,CityNames[1])) << "We should have none " << CityNames[1] << " but it is still in the vector so the function removeCitiesInVectorThatAreSmallerThanMe is working wrong";

    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
   ClosestCity:: removeCitiesInVectorThatAreSmallerThanMe(vec,CityNames[1]);
    ASSERT_EQ(2, vec.size()) << "We should erase cities smaller than Lodz and have two cities in vector Lodz and Warsaw than but we have: " << vec.size() << " of them";
    ASSERT_TRUE(findCity(vec,CityNames[0])) << "We should have one " << CityNames[0] << " but we found" << findCity(vec,CityNames[0]);
    ASSERT_TRUE(findCity(vec,CityNames[1])) << "We should have one " << CityNames[1] << " but we found" << findCity(vec,CityNames[1]);
    ASSERT_FALSE(findCity(vec,CityNames[2])) << "We should have none " << CityNames[2] << " but it is still in the vector so the function removeCitiesInVectorThatAreSmallerThanMe is working wrong";
    
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    ClosestCity::removeCitiesInVectorThatAreSmallerThanMe(vec,CityNames[2]);
    ASSERT_EQ(7, vec.size()) << "We should erase cities smaller than Szczecin and therefore have seven cities in vector but we have: " << vec.size() << " of them";
    ASSERT_TRUE(findCity(vec,CityNames[0])) << "We should have one " << CityNames[0] << " but we found" << findCity(vec,CityNames[0]);
    ASSERT_TRUE(findCity(vec,CityNames[1])) << "We should have one " << CityNames[1] << " but we found" << findCity(vec,CityNames[1]);
    ASSERT_TRUE(findCity(vec,CityNames[2])) << "We should have one " << CityNames[2] << " but we found" << findCity(vec,CityNames[2]);
    ASSERT_TRUE(findCity(vec,CityNames[4])) << "We should have one " << CityNames[4] << " but we found" << findCity(vec,CityNames[4]);
    ASSERT_FALSE(findCity(vec,CityNames[3])) << "We should have none " << CityNames[3] << " but it is still in the vector so the function removeCitiesInVectorThatAreSmallerThanMe is working wrong";
    
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    ClosestCity::removeCitiesInVectorThatAreSmallerThanMe(vec,CityNames[3]);
   ASSERT_EQ(10, vec.size()) << "We should erase none city as we have nocity smaller than Katowice in vector but we have: " << vec.size() << " of them";
    ASSERT_TRUE(findCity(vec,CityNames[0])) << "We should have one " << CityNames[0] << " but we found" << findCity(vec,CityNames[0]);
    ASSERT_TRUE(findCity(vec,CityNames[1])) << "We should have one " << CityNames[1] << " but we found" << findCity(vec,CityNames[1]);
    ASSERT_TRUE(findCity(vec,CityNames[2])) << "We should have one " << CityNames[2] << " but we found" << findCity(vec,CityNames[2]);
    ASSERT_TRUE(findCity(vec,CityNames[3])) << "We should have one " << CityNames[3] << " but we found" << findCity(vec,CityNames[3]);
    ASSERT_TRUE(findCity(vec,CityNames[4])) << "We should have one " << CityNames[4] << " but we found" << findCity(vec,CityNames[4]);
    
    // testing with flags and messages
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    
    std::string NextCity = ClosestCity::getTheClosestCityThatIsBiggerThanMe(vec,CityNames[0]);

   ASSERT_EQ("", NextCity) << "As Warsaw is the biggest city we expect the function to return us empty string "" but we got: " << NextCity;
    
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    
    NextCity = ClosestCity::getTheClosestCityThatIsBiggerThanMe(vec,CityNames[1]);

    ASSERT_EQ(CityNames[0], NextCity) << "For second biggest city Lodz we expect the function to return us the biggest city Warsaw but we got: " << NextCity;
    
    vec.clear();
   vec = DatabaseReader::readCitiesFromFile(path);
    
    NextCity = ClosestCity::getTheClosestCityThatIsBiggerThanMe(vec,CityNames[2]);

    ASSERT_EQ(CityNames[4], NextCity) << "For the city "<< CityNames[2] <<" we expect the function to return us Poznan but we got: " << NextCity;
    
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    
    NextCity = ClosestCity::getTheClosestCityThatIsBiggerThanMe(vec,CityNames[3]);

    ASSERT_EQ(CityNames[5], NextCity) << "For the city "<< CityNames[3] <<" we expect the function to return us Lublin but we got: " << NextCity;

        
    // testing getAllBiggestCitiesInOrder
   
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    std::string cities_list = ClosestCity::getAllBiggestCitiesInOrder(vec,CityNames[0]);
    std::string correct_list ="Warsaw";
    
    ASSERT_EQ(correct_list, cities_list) << "We should have a following list of cities: " << correct_list << " but we have: " << cities_list;
    
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    
    cities_list = ClosestCity::getAllBiggestCitiesInOrder(vec,CityNames[1]);
    correct_list ="Lodz->Warsaw";
     
    ASSERT_EQ(correct_list, cities_list) << "We should have a following list of cities: " << correct_list << " but we have: " << cities_list;
    
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    
    cities_list = ClosestCity::getAllBiggestCitiesInOrder(vec,CityNames[2]);
    correct_list ="Szczecin->Poznan->Wroclaw->Lodz->Warsaw";
    
    ASSERT_EQ(correct_list, cities_list) << "We should have a following list of cities: " << correct_list << " but we have: " << cities_list;
    
    vec.clear();
    vec = DatabaseReader::readCitiesFromFile(path);
    
    cities_list = ClosestCity::getAllBiggestCitiesInOrder(vec,CityNames[3]);
    correct_list ="Katowice->Krakow->Lodz->Warsaw";
    
    ASSERT_EQ(correct_list, cities_list) << "We should have a following list of cities: " << correct_list << " but we have: " << cities_list;
    
}
int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
