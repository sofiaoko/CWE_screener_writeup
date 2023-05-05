# Closest

There was one file to download titled "addresses.csv," and I downloaded this file and opened it in Excel to look at the data.

The spreadsheet contained a list with three columns for names, street adresses, and cities.
<img width="570" alt="close2" src="https://user-images.githubusercontent.com/97570623/236563692-a7a0bd89-b619-4866-8e1b-63e190098226.PNG">


To geocode all of the addresses, I used Geoapify (https://www.geoapify.com/tools/geocoding-online). Putting the addresses into this website would return a spreadsheet with two columns for the latitude and longitude for each address, along with other additional address components. The only limitation of this website was that it only allowed for up to 500 rows of input, so I decided to split the addresses.csv file into shorter, separate files.

<img width="466" alt="close4" src="https://user-images.githubusercontent.com/97570623/236562211-45289fc0-48f7-42f7-a234-c5c1cee9dd1d.PNG">

To satisfy Geoapify's formatting requirements, I added a header row for each spreadsheet.

<img width="181" alt="close3" src="https://user-images.githubusercontent.com/97570623/236562401-9f701739-38f6-4efe-9bd1-eeef0aa05899.PNG">


I uploaded each spreadhseet to Geoapify, and downloaded the geocoded spreadsheets. I combined the three geocoded spreadsheets into one large spreadsheet that included all of the original addresses. The geocoded spreadsheets initially had extra columns with extraneous address information, but I deleted the extra columns so that the only columns were Street Address, City, Longitude, and Longitude, along with 3 extra columns I added.
<img width="925" alt="close" src="https://user-images.githubusercontent.com/97570623/236562195-27d09434-5e28-4692-b0f1-774d6b6be11b.PNG">

<img width="870" alt="close5" src="https://user-images.githubusercontent.com/97570623/236562470-b1418d29-f31d-41da-8324-e72de949dd47.PNG">


I added cells in the spreadsheeet that contained the target latitude/longitude I was trying to find a closest match to (highlighted yellows). I created a column that took the absolute value of a cell's latitude minus the target latitude, and additional column for longitude. The third column (Column G) I added took the sum of the cells of the E and F column for a specific row. Finally, I sorted the entire spreadsheet by Column G so that all of the addresses were sorted so that the topmost addresses had the least absolute distance from the target coordinates.

Using the name that correlated with the top address did not solve the challenge. If I remember correctly, the third or fourth address from my sorted spreadsheet was accepted by the challenge. The first time I solved this challenge in a previous screener, I used the provided geocoder website from the challenge and got the correct flag my first attempt at sorting. This time I used a separate geocoder, so I am assuming that there were minor differences between how Geoapify calculated the coordinates I received versus the census's geocoding software.
