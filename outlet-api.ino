// Import required libraries
#include <ESP8266WiFi.h>
#include <aREST.h>
#include <RCSwitch.h>

// Create aREST instance
aREST rest = aREST();

// WiFi parameters
const char* ssid     = "<SSID>";
const char* password = "<SSID_PASSPHRASE>";

// The port to listen for incoming TCP connections
#define LISTEN_PORT           80

// Create an instance of the server
WiFiServer server(LISTEN_PORT);

RCSwitch mySwitch = RCSwitch();

// Pin connections to board
void setup(void) {
  Serial.begin(115200);

  mySwitch.enableTransmit(13);  // Receiver on interrupt GPio 13 => that is pin D7 
  Serial.println("ESP8266 RF transmitter starting now...");

  // Function to be exposed
  rest.function("one",button_one);
  rest.function("two",button_two);
  rest.function("three",button_three);
  rest.function("four",button_four);
  rest.function("five",button_five);
  
  // Give name & ID to the device (ID should be 6 characters long)
  rest.set_id("5");
  rest.set_name("etekcy");

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {

  // Handle REST calls
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }
  rest.handle(client);
}

// Custom function accessible by the API
int button_one(String command) {
  // Get state from command
  int state = command.toInt();
  Serial.println(state);
  if (state == 1) {
    Serial.println("Turning 1 on");
    mySwitch.setPulseLength(183);
    mySwitch.send(1332531, 24);
    delay(100);
  }
  if (state == 0) {
    Serial.println("Turning 1 off");
    mySwitch.setPulseLength(183);
    mySwitch.send(1332540, 24);
    delay(100);
  }
  return state;
}

int button_two(String command) {
  // Get state from command
  int state = command.toInt();
  Serial.println(state);
  if (state == 1) {
    Serial.println("Turning 2 on");
    mySwitch.setPulseLength(183);
    mySwitch.send(1332675, 24);
    delay(100);
  }
  if (state == 0) {
    Serial.println("Turning 2 off");
    mySwitch.setPulseLength(183);
    mySwitch.send(1332684, 24);
    delay(100);
  }
  return state;
}

int button_three(String command) {
  // Get state from command
  int state = command.toInt();
  Serial.println(state);
  if (state == 1) {
    Serial.println("Turning 3 on");
    mySwitch.setPulseLength(183);
    mySwitch.send(1332995, 24);
    delay(100);
  }
  if (state == 0) {
    Serial.println("Turning 3 off");
    mySwitch.setPulseLength(183);
    mySwitch.send(1333004, 24);
    delay(100);
  }
  return state;
}

int button_four(String command) {
  // Get state from command
  int state = command.toInt();
  Serial.println(state);
  if (state == 1) {
    Serial.println("Turning 4 on");
    mySwitch.setPulseLength(183);
    mySwitch.send(1334531, 24);
    delay(100);
  }
  if (state == 0) {
    Serial.println("Turning 4 off");
    mySwitch.setPulseLength(183);
    mySwitch.send(1334540, 24);
    delay(100);
  }
  return state;
}

int button_five(String command) {
  // Get state from command
  int state = command.toInt();
  Serial.println(state);
  if (state == 1) {
    Serial.println("Turning 5 on");
    mySwitch.setPulseLength(183);
    mySwitch.send(1340675, 24);
    delay(100);
  }
  if (state == 0) {
    Serial.println("Turning 5 off");
    mySwitch.setPulseLength(183);
    mySwitch.send(1340684, 24);
    delay(100);
  }
  return state;
}

