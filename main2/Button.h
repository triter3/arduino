#ifndef Button_h
#define Button_h

class Button
{
 public:
  Button(int number, int pin, int min_val, int max_val);
  bool check();
  int getNumber();
 private:
  long nowTime;
  long afterTime;
  int _number;
  int _pin;
  int _maxVal;
  int _minVal;  
  int val;
};

#endif

