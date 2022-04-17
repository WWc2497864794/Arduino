#include <DHT.h>
#define DHTPIN D4
#define DHTTYPE DHT11
DHT dht (DHTPIN,DHTTYPE);

/* 
double Fahrenheit(double celsius)
{
  return 1.8 * celsius + 32; //摄氏温度度转化为华氏温度
}
 
double Kelvin(double celsius)
{
  return celsius + 273.15; //摄氏温度转化为开氏温度
}
 */
void setup()
{
  Serial.begin(115200);//设置波特率为115200
  dht.begin();
}

void loop()
{
  delay(1000);

  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();

  //如果温度湿度有一个为空，则输出“获=获取值失败”
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

   //输出温度
  Serial.print(t);
  Serial.print("℃");
  Serial.print(",");
  //输出湿度
  Serial.print(h);
  Serial.println("%");
 
}
