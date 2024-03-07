#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

#define LED 26

const char* ssid = "Wi-Fi Maison des Élèves"; // Wifi network name
const char* password = "w1f1delaME139";         // Wifi network password

// Setup wifi connection inspired on TB3 project code

void setup() {
  //Connecting to wifi
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  pinMode(LED, OUTPUT);
  Serial.print("Starting Wifi connection...");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi");
  }
  
  Serial.println("Connected to WiFi");

  // Moock test for the code, using code snippets and API from https://www.youtube.com/watch?v=cgoCmYLeaSI
  // Chooses a random id number for range of answers purprose, considering a API that overwrites the results, this is not necessary. 
  //Consering a API that stocks all answers should be changed to the id of the question answered.

  long rnd = random(1,6); 
  HTTPClient client;

  client.begin("https://jsonplaceholder.typicode.com/posts/1/comments?id=" + String(rnd)); // url API
  int httpCode = client.GET();

  // Gets the json element from the API and selects 
  if (httpCode > 0) {
    String payload = client.getString();
    Serial.println(payload); // Used to bebug and verify if the code is correctly fetching from API

    StaticJsonDocument<200> doc;
    deserializeJson(doc, payload);

    // Check if the JSON response is an array
    // done to adapt to the moock API; suggested by ChatGPT during a debug of the original code from Ref[2]
    // I was getting both zeros even if the correct JSON document was being fetched 
    //In the JSON response from the API endpoint acessed, there's no direct postId or id field at the root level of the JSON object. 
    //Instead, it is an array of objects, containing postId and id fields.
    // the solution found was the following condition of acessing through JsonArray and JsonObject ref [7] and [8]

    if (doc.is<JsonArray>()) {
      // Access the first element of the array

      JsonObject firstElement = doc[0];

      // Access postId and id fields and changes to represent answers ids

      int idCorrectOption = firstElement["postId"];
      int idChosenOption = firstElement["id"];
      // int questionNumber=firstElement["questionNumber"] // suposing a API with the question number
      // const char* questionName= firstElement["questionName"] // suposing a API with only question title

      // Print information fetched
      // Serial.print("Question Number: ");// if only question title make the substitution with Question Name and questionName
      // Serial.println(questionNumber);
      Serial.print("id Correct Option: ");
      Serial.println(idCorrectOption);
      Serial.print("id Chosen Option: ");
      Serial.println(idChosenOption);

      
      // Checks if the answer is correct
      // Led behaviour code was also inpired by source code of TB3 project code

      if (idCorrectOption == idChosenOption) {
        // reacts to correct answer blinking slow and printing correct!!

        digitalWrite(LED, HIGH);
        delay(1500); 
        digitalWrite(LED, LOW);
        delay(1500);
        digitalWrite(LED, HIGH);
        delay(1500);
        digitalWrite(LED, LOW);
        delay(1500);
        digitalWrite(LED, HIGH);
        delay(1500);
        digitalWrite(LED, LOW);

        Serial.println("Correct!!");
      } else {
        //Reacts to the wrong answer blinking fast and printing wrong answer

        digitalWrite(LED, HIGH);
        delay(800);
        digitalWrite(LED, LOW);
        delay(800);
        digitalWrite(LED, HIGH);
        delay(800);
        digitalWrite(LED, LOW);
        delay(800);
        digitalWrite(LED, HIGH);
        delay(800);
        digitalWrite(LED, LOW);

        Serial.println("Wrong answer.");
      }
    } else {
      Serial.println("Invalid JSON format: expected an array.");
    }
  } else {
    Serial.println("Error on HTTP request");
  }
  client.end();
}

void loop() {
  // Nothing to do in the loop for this code (expected to be called again each time the student answers)
}
