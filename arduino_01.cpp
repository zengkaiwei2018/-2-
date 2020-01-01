#define ERROR -1

typedef bool MODE;

int ledpin=13;//定义数字接口13

void setup() {

  // 设置的代码放这, 运行一次:

  pinMode(ledpin,OUTPUT);

}

const int Moers[36][5]={{0,1,3,3,3},

                  {1,0,0,0,3},

                  {1,0,1,0,3},

                  {1,0,0,3,3},

                  {0,3,3,3,3},

                  {0,0,1,0,3},

                  {1,1,0,3,3},

                  {0,0,0,0,3},

                  {0,0,3,3,3},

                  {0,1,1,1,3},

                  {1,0,1,3,3},

                  {0,1,0,0,3},

                  {1,1,3,3,3},

                  {1,0,3,3,3},

                  {1,1,1,0,0},

                  {0,1,1,0,3},

                  {1,1,0,1,3},

                  {0,1,0,3,3},

                  {0,0,0,3,3},

                  {1,3,3,3,3},

                  {0,0,1,3,3},

                  {0,0,0,1,3},

                  {0,1,1,3,3},

                  {1,0,0,1,3},

                  {1,0,1,1,3},

                  {1,1,0,0,3},

                  {0,1,1,1,1},

                  {0,0,1,1,1},

                  {0,0,0,1,1},

                  {0,0,0,0,1},

                  {0,0,0,0,0},

                  {1,0,0,0,0},

                  {1,1,0,0,0},

                  {1,1,1,0,0},

                  {1,1,1,1,0},

                  {1,1,1,1,1}};

const char achar[36]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};

//control light

void Con_Light(bool sq)

{

  //sq = 0 :short  1000ms

  //sq = 1 :long   3000ms

  //digitalWrite(13,HIGH)

  //delay( /ms)

  if(sq)  //long

  {

    digitalWrite(ledpin,LOW);

    delay(100);

    digitalWrite(ledpin,HIGH);

    delay(2000);

  }

  else

  {

    digitalWrite(ledpin,LOW);

    delay(100);

    digitalWrite(ledpin,HIGH);

    delay(500);

  }

}

  

//find word you want put

int FindLine(char a)

{

  int i =0;

  while(a!='#')
  {

    if(achar[i] == a)
    {
      return i;

    }

    i++;

  }

  return ERROR;  //stand for error;

}

void Put_Light(int j)

{

  for(int i=0;i<5;i++)
  {

    if(Moers[j][i] == 3) break;

    else

    {

      Con_Light(Moers[j][i]);

    }

  }

}

void end()
{

  digitalWrite(ledpin,HIGH);

  delay(10000);

}

void loop() {

  // 主代码, 重复运行:

  char s[5] = "HELL0#";

  for(int i=0;i<5;i++)

  {

    Put_Light(FindLine(s[i]));

  }

  end();

}
