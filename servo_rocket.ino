/*
 * Copyright (C) 2023  SuperGreenLab <towelie@supergreenlab.com>
 * Author: Constantin Clauzel <constantin.clauzel@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

bool isOn = false;
int nOn = 0;
unsigned long lastOn = 0;

void setup() {
  pinMode(1, OUTPUT);
}

void loop() {
  bool newIsOn = digitalRead(2);
  if (newIsOn && !isOn) {
    lastOn = micros();
  } else if (!newIsOn && isOn) {
    if (micros () - lastOn >1500) {
      nOn++;
    } else {
      nOn = 0;
    }
  }
  isOn = newIsOn ;

  if (nOn >= 25) {
    digitalWrite(1, LOW);
  } else if (nOn >= 5) {
    digitalWrite(1, HIGH);
  } else {
    digitalWrite(1, LOW);
  }
}
