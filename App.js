import React from 'react';
import { View, Button, Text, StyleSheet, TouchableOpacity } from 'react-native';
import axios from 'axios';

const esp8266Ip = 'http://192.168.1.156'; // Replace with the IP address displayed by the ESP8266

export default function App() {
  const sendCommand = (command) => {
    axios.get(`${esp8266Ip}/move?dir=${command}`)
      .then(response => console.log(response.data))
      .catch(error => console.error("Error sending command:", error));
  };

  const setSpeed = (speed) => {
    axios.get(`${esp8266Ip}/setSpeed?value=${speed}`)
      .then(response => console.log(response.data))
      .catch(error => console.error("Error setting speed:", error));
  };

  return (
    <View style={styles.container}>
      <Text style={styles.title}>Remote Control Car</Text>
      <View style={styles.joystick}>
        <TouchableOpacity style={styles.button1} onPress={() => sendCommand('F')}>
          <Text style={styles.buttonText}>▲</Text>
        </TouchableOpacity>
        <View style={styles.horizontalButtons}>
          <TouchableOpacity style={styles.button} onPress={() => sendCommand('L')}>
            <Text style={styles.buttonText}>◀</Text>
          </TouchableOpacity>
          <TouchableOpacity style={styles.button} onPress={() => sendCommand('S')}>
            <Text style={styles.buttonText}>⏹</Text>
          </TouchableOpacity>
          <TouchableOpacity style={styles.button} onPress={() => sendCommand('R')}>
            <Text style={styles.buttonText}>▶</Text>
          </TouchableOpacity>
        </View>
        <TouchableOpacity style={styles.button1} onPress={() => sendCommand('B')}>
          <Text style={styles.buttonText}>▼</Text>
        </TouchableOpacity>
      </View>
      <View style={styles.speedControls}>
        <Button title="Medium Speed" onPress={() => setSpeed(210)} />
        <Button title="Fast Speed" onPress={() => setSpeed(255)} />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: { flex: 1, justifyContent: 'center', alignItems: 'center', padding: 20 },
  title: { fontSize: 24, marginBottom: 20 },
  joystick: { alignItems: 'center', marginBottom: 20 },
  horizontalButtons: { flexDirection: 'row', justifyContent: 'space-between', width: 150 },
  button: { 
    backgroundColor: '#ddd', 
    borderRadius: 50, 
    padding: 15, 
    margin: 5, 
    alignItems: 'center', 
    justifyContent: 'center' 
  },
  button1: { 
    backgroundColor: '#ddd', 
    borderRadius: 50, 
    padding: 15, 
    margin: 5,
    marginLeft: 38, 
    alignItems: 'center', 
    justifyContent: 'center' 
  },
  buttonText: { fontSize: 20 },
  speedControls: { flexDirection: 'row', justifyContent: 'space-around', width: '100%', marginBottom: 20 }
});
