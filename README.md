# TB3_Rattrapage_Embarquee_LAURAPRADO
Work done for the Toolbox 3 of the ICM course at the École des Mines de Saint-Étienne in  onboard (Embarquée) programming in march 2024

## Guide for running the code

1. Configure the Arduino IDE by going to File > Preferences > Additional boards manager URLs and add the following URL: https://dl.espressif.com/dl/package_esp32_index.json.
2. Install the ESP32 board support in the Arduino IDE.
3. Select the ESP32 Wrover Module as your target board in the IDE settings.
4. Install/Check if you have installed the libraries declared at the begging of the code. They are listed in ref [] and [].
5. Connect the board to the computer and click on "Upload" in the Arduino IDE interface.
6. Monitor the code output through the Serial Monitor.

## References
Apart from the classroom material the following sources were used to produce the code in this work:
1. TB3 Final Project code. Ref[1] (https://github.com/ho0dlumx/TB3-nixegourmet-embarqueee)
2. ESP32 GET JSON from API - ESP32 GET request from API receive JSON. Ref[2] (https://www.youtube.com/watch?v=cgoCmYLeaSI)
3. Official Random documentation. Ref[3] (https://www.arduino.cc/reference/en/language/functions/random-numbers/random/)
4. StacticJson official documentation. Ref[4] (https://arduinojson.org/v6/api/staticjsondocument/)
5. ArduinoJson official documentation. Ref[5] (https://arduinojson.org/?utm_source=meta&utm_medium=library.properties)
6. HTTPClient official documentation. Ref[6] (https://github.com/amcewen/HttpClient)

## API
In order to complete the given task of this project, the same API used in ref[2] was the one put to test, in order to simulate the other rattrapage works API. 
Although the format is far different from what most likely the project's API should be, the API still work to prove the correct fetching and analysis of API JSON's response data. 
For this, the data stored in "postId" and "id" were considered respectively the correct response index and user- the student- response. 
As both are designed as numbers, ids, in the original API use, they served as the responses indexes, as indicated in the problem's statement for this work.
Although these indexes are supposed to be restricted from 0 to 3, the code works regardless of the number of answers possible and expects the API to set these parameters.
