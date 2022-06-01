#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "UKR");

	cout << "Укажите количество очков здоровья дракона: ";
	int dragonhealth;
	cin >> dragonhealth;

	cout << "Укажите количество очков атаки дракона: ";
	int dragonattack;
	cin >> dragonattack;

	cout << "Укажите количество очков здоровья копейщика: ";
	int spearhealth;
	cin >> spearhealth;

	cout << "Укажите количество очков атаки копейщика: ";
	int spearattack;
	cin >> spearattack;

	int battledragonhealth = dragonhealth;
	int battlespearhealth = spearhealth;

	int battlespearattack = spearattack;

	int temp = 0;

	int numspear = 1;

	int modifier = dragonhealth / 34;

	int spear = spearhealth;

	while (true)
	{
		battledragonhealth -= battlespearattack;
		battlespearhealth -= dragonattack;
		temp += dragonattack;
		spearhealth = spear;

		if (battlespearhealth <= 0)
		{
			battlespearhealth = spearhealth * numspear;
			battlespearhealth += spearhealth;
			numspear += 1 * modifier;
			battlespearattack = spearattack * numspear;
			battledragonhealth = dragonhealth;
		}
		if (temp > spearhealth)
		{
			numspear -= (temp / spearhealth);
			battlespearhealth -= spearhealth * (temp / spearhealth);
			battlespearattack -= spearattack * (temp / spearhealth);
			temp -= spearhealth * (temp / spearhealth);
		}
		if (temp < spearhealth && temp > 0)
		{
			spearhealth -= temp;
		}
		if (battledragonhealth <= 0)
		{
			break;
		}
		temp = 0;
	}

	double num = dragonattack / spear;

	if (battledragonhealth <= 0 && numspear > 0)
	{
		battledragonhealth = dragonhealth;
		battlespearhealth = spearhealth * numspear;
		battlespearattack = spearattack * numspear;

		while (true)
		{
			battledragonhealth -= battlespearattack;
			cout << "\nКопейщики атакуют (урон " << battlespearattack << ") - у дракона осталось " << battledragonhealth << " очков здоровья.\n";
			if (battledragonhealth > 0)
			{
				battlespearhealth -= dragonattack;
				temp += dragonattack;
				cout << "Дракон атакует (урон " << dragonattack << ") - осталось копейщиков: " << (battlespearattack / 10) - num << "\n\n";
				if (spearhealth < spear)
				{
					cout << "Один из копейщиков ранен (осталось очков здоровья: " << spearhealth << ").\n\n";
				}
			}

			spearhealth = spear;

			if (temp > spearhealth)
			{
				numspear -= (temp / spearhealth);
				battlespearhealth -= spearhealth * (temp / spearhealth);
				battlespearattack -= spearattack * (temp / spearhealth);
				temp -= spearhealth * (temp / spearhealth);
			}
			if (temp < spearhealth && temp > 0)
			{
				spearhealth -= temp;
			}
			if (dragonattack < spear && spearhealth == temp)
			{
				numspear -= 1;
				battlespearhealth -= spearhealth;
				battlespearattack -= spearattack;
			}
			if (battledragonhealth <= 0)
			{
				cout << "\nПобеда\n";
				int result = (battlespearattack / 10) - num;
				if (spear > dragonattack)
				{
					numspear = result;
				}
				cout << "Осталось копейщиков в живых: " << numspear << "\n";
				break;
			}
			temp = 0;
		}
	}
}
