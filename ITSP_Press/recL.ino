int recieve()
{
	bool started=false;
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
		return value;
	}
}

void sendL(int value)
{
	Serial.print('L');
	Serial.print(value);
	Serial.println('>');
}

void setup()
{
//setup pins
}

void loop()
{

	int speed=recieve();
	//send speed value to motor driver

}
