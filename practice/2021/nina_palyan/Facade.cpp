#include <string>
#include <iostream>
using namespace std;

class Alarm
{
public:
	void AlarmOn()
	{
		cout << "Alarm is on" << endl;
	}

	void AlarmOff()
	{
		cout << "Alarm is off" << endl;
	}
};

class Notif
{
public:
	void NotifOn()
	{
		cout << "Notif is on" << endl;
	}

	void NotifOff()
	{
		cout << "Notif is off" << endl;
	}
};

class Sms
{
public:
	void SMSOn()
	{
		cout << "SMS is on" << endl;
	}

	void SMSOff()
	{
		cout << "SMS is off" << endl;
	}
};

class Ring
{
public:
	void RingOn()
	{
		cout << "Ring is on" << endl;
	}

	void RingOff()
	{
		cout << "Ring is off" << endl;
	}
};

class PhoneCall
{
	Alarm alarm;
	Notif notif;
	Sms sms;
	Ring ring;

public:
	PhoneCall() {}

	void AtWork()
	{
		alarm.AlarmOff();
		notif.NotifOff();
		sms.SMSOn();
		ring.RingOff();
		cout << "At Work mode activated\n";
	}

	void Meeting()
	{
		alarm.AlarmOff();
		notif.NotifOff();
		sms.SMSOff();
		ring.RingOff();
		cout << "Meeting mode activated\n";
	}

	void AtHome()
	{
		alarm.AlarmOn();
		notif.NotifOn();
		sms.SMSOn();
		ring.RingOn();
		cout << "At Home mode activated\n";
	}
};

int main()
{
	PhoneCall pc;
	pc.AtWork();
	pc.Meeting();
	pc.AtHome();

	return 0;
}