RDC ESP32 R1/R2上で，ESP32Servo.h の補完用に，
ledcWrite() を用い，サーボモーターに必要な50HzのPWM信号（周期20ms）を生成する．
Lssuesを参照ください

const int servoPin = 18; // PWM出力ピン
const int pwmChannel = 0; // 使用するPWMチャネル
const int pwmFreq = 50; // サーボ用のPWM周波数（50Hz）
const int pwmResolution = 16; // 分解能（16ビット）

※ライブラリ化を行わす，ledcWrite() で直接コードを書く方向で再考中です．
　理由は，生成AIとの相性
