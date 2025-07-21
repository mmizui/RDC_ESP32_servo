RDC ESP32 R1/R2を用いたロボットにて，ESPservo.h でのPWMの出力が上手くいかない．
対応として，
ESP32の ledcWrite() を用い，サーボモーターに必要な50HzのPWM信号（周期20ms）を生成する．

覚書
const int servoPin = 18; // PWM出力ピン
const int pwmChannel = 0; // 使用するPWMチャネル
const int pwmFreq = 50; // サーボ用のPWM周波数（50Hz）
const int pwmResolution = 16; // 分解能（16ビット）

//事前準備
void setup() {
ledcSetup(pwmChannel, pwmFreq, pwmResolution); // PWMチャネルの設定
ledcAttachPin(servoPin, pwmChannel); // ピンにチャネルを割り当て
}

//サーボ角を中立（90°）へ指示
void loop() {
int angle = 90; // 例：90度に設定

// サーボの角度をPWMデューティ比に変換（0度=500us, 180度=2400us）
int duty_us = map(angle, 0, 180, 500, 2400); // パルス幅（マイクロ秒）
int maxDuty = (1 << pwmResolution) - 1;
int duty = (duty_us * pwmFreq * maxDuty) / 1000000; // デューティ比に変換

ledcWrite(pwmChannel, duty); // PWM出力
delay(1000);
}

このソースをライブラリ化し，
moveServo(angle) 関数で任意の角度に移動

１．ServoPWM.h と ServoPWM.cpp をダウンロード
２．Arduino IDE の libraries フォルダに ServoPWM という名前のフォルダを作成
３．その中に2つのファイルを保存
４．Arduino IDE を再起動し、#include <ServoPWM.h> で使用可能に
