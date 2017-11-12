/**
 * @file city.cpp
 *
 * @author Jaroslaw Wiosna
 * @author Wojciech Mielczarek
 * @par Licence
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.4. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 */

#include "City.hpp"
#include <cmath>
#include <gtest/gtest.h>

TEST(City, CityClassTests) {
    std::string city_data[5] = {"Aleksandrow Kujawski", "7.23", "12335",
                                "52.8833", "18.7"};
    City city1(city_data[0], city_data[1], city_data[2], city_data[3],
               city_data[4]);

    // testing if constructor with only strings
    ASSERT_EQ(city_data[0], city1.getName())
        << "The city created with the constructor has a wrong name";
    ASSERT_EQ(7.23, city1.getArea())
        << "The city created with the constructor has a wrong area";
    ASSERT_EQ(12335, city1.getPopulation()) << "The city created with the "
                                               "constructor has a wrong "
                                               "population number";
    ASSERT_EQ(city_data[3], city1.getLatitude())
        << "The city created with the constructor has a wrong langitiude";
    ASSERT_EQ(city_data[4], city1.getLongitude())
        << "The city created with the constructor has a wrong longitude";
    ASSERT_EQ(0, city1.getDistanceToTheFarthest())
        << "The city created with the constructor has a wrong distance to the "
           "farthest city. It should be 0";

    std::string city2_name = "Bielsko-Biala";
    double city2_area = 124.51;
    std::size_t city2_population = 172030;
    std::string city2_latitude = "49.8333";
    std::string city2_longtitude = "19.0667";
    City city2(city2_name, city2_area, city2_population, city2_latitude,
               city2_longtitude);

    // testing if constructor with string and numbers works
    ASSERT_EQ(city2_name, city2.getName())
        << "The city created with the constructor has a wrong name";
    ASSERT_EQ(124.51, city2.getArea())
        << "The city created with the constructor has a wrong area";
    ASSERT_EQ(city2_population, city2.getPopulation())
        << "The city created with the constructor has a wrong population "
           "number";
    ASSERT_EQ(city2_latitude, city2.getLatitude())
        << "The city created with the constructor has a wrong langitiude";
    ASSERT_EQ(city2_longtitude, city2.getLongitude())
        << "The city created with the constructor has a wrong longitude";
    ASSERT_EQ(0, city2.getDistanceToTheFarthest())
        << "The city created with the constructor has a wrong distance to the "
           "farthest city. It should be 0";


    // testing getAllFields function(7.230000 instead of 7.23 because std
    // to_string sets precision to 6
    ASSERT_EQ("Aleksandrow Kujawski 7.230000 12335 52.8833 18.7 0 ;",
              city1.getAllFields())
        << "getAllFields function should return us Aleksandrow Kujawski "
           "7.230000 12335 52.8833 18.7 0 ; but it was: "
        << city1.getAllFields();
    ASSERT_EQ("Bielsko-Biala 124.510000 172030 49.8333 19.0667 0 ;",
              city2.getAllFields())
        << "getAllFields function should return us Bielsko-Biala 124.510000 "
           "172030 49.8333 19.0667 0 ; but it was: "
        << city2.getAllFields() << " " << city2.getArea();

    // testing setDistanceToTheFarthest
    std::size_t distance = 222;
    city1.setDistanceToTheFarthest(distance);
    ASSERT_EQ(distance, city1.getDistanceToTheFarthest())
        << "DistanceToTheFarthest should be set by setDistanceToTheFarthest to "
           "the value "
        << distance << " but it was " << city1.getDistanceToTheFarthest();
    std::size_t distance2 = 33.3;
    city2.setDistanceToTheFarthest(distance2);
    ASSERT_EQ(distance2, city2.getDistanceToTheFarthest())
        << "DistanceToTheFarthest should be set by setDistanceToTheFarthest to "
           "the value "
        << distance2 << " but it was " << city2.getDistanceToTheFarthest();

    std::string city_data3[5] = {"Lodz", "293.25", "696503", "51.7833",
                                 "19.4667"};
    City city3(city_data3[0], city_data3[1], city_data3[2], city_data3[3],
               city_data3[4]);

    // testing haversineFormula is not included as we would have to call it the
    // same way that distanceFrom does and the function itself does nothing else

    // testing distanceFrom
    double distanceBetweenCities1v2 = city1.distanceFrom(city2);
    double distanceBetweenCities2v2 = city2.distanceFrom(city3);
    double distanceBetweenCities3v2 = city1.distanceFrom(city3);

    std::size_t distances_expected[] = {340, 219, 133};
    ASSERT_EQ(distances_expected[0],
              (std::size_t)std::round(distanceBetweenCities1v2))
        << "Distance claculated by distanceFrom is wrong, it should be: "
        << distances_expected[0];
    ASSERT_EQ(distances_expected[1],
              (std::size_t)std::round(distanceBetweenCities2v2))
        << "Distance claculated by distanceFrom is wrong, it should be: "
        << 339.926;
    ASSERT_EQ(distances_expected[2],
              (std::size_t)std::round(distanceBetweenCities3v2))
        << "Distance claculated by distanceFrom is wrong, it should be: "
        << 339.926;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
