void sendL(int value)
{
	Serial.print('L');
	Serial.print(value);
	Serial.println('>');
}

void sendR(int value)
{
	Serial.print('R');
	Serial.print(value);
	Serial.println('>');
}

int left_press=0;
int right_press=0;
int speed=100;
int k=1;
int a=1;
//values require tuning

int recieve()
{
	bool started=false;
	bool left=false;
	bool ended=false;
	char incomingByte;
	char msg[3];
	byte[index];
	while(Serial.available()>0)
	{
		incomingByte=Serial.read();
		if(incomingByte=='L')
		{
			started=true;
			left=true;
			index=0;
			msg[index]='\0';
		}
		else if(incomingByte=='R')
		{
			started=true;
			left=false;
			index=0;
			msg[index]='\0';
		}
		else if(incomingByte=='>')
		{
			ended=true;
			break;
		}
		else
		{
			if(index<4)
			{
				msg[index]=incomingByte;
				index++;
				msg[index]='\0';
			}
		}
	}

	if(started && ended)
	{
		int value=atoi(msg);
		if(left)
		{left_press=value;}
		else
		{right_press=value;}
		return value;
	}
}

void setup() {
//setup pins
}

void loop() {
	recieve();
	sendL(speed+left_press-right_press);
	sendR(speed+right_press-left_press);
}

