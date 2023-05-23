#include "func_drink.h"

void DataEntryDrink(Drink* (&d), int& n) {
	cout << "Enter data acount";
	cin >> n;

	d = new Drink[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter id :";
		cin >> d[i].id;
		cout << "Enter bar id: ";
		cin >> d[i].barId;
		cout << "Name: ";
		cin >> d[i].name;


		cout << "___________________________________" << endl;
	}
}

void ReadingDataDrink(Drink* (&d), int& n, string foleName) {
	ifstream reading(foleName);
	if (reading) {
		reading >> n;
		d = new Drink[n];

		for (int i = 0; i < n; i++) {
			reading >> d[i].id;
			reading >> d[i].barId;
			reading >> d[i].name;
		}
	}
	else {
		cout << "Error with open file";
	}

	reading.close();
}

void PrintDrink(Drink* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Drink: #" << i + 1 << ":" << endl;

		cout << "Id, bar id and name drink:\n" <<
			"Id: " << d[i].id << 
			"\nBar id: " << d[i].barId <<
			"\nName: " << d[i].name << endl;

		cout << "______________________" << endl;
	}
}

void DataChangeDrink(Drink* (&d), int n) {
	int _n;

	cout << "Enter number of drink: ";
	cin >> _n;
	_n--;

	

	if (_n >= 0 && _n < n) {
		//cout << "Enter id: ";
		//cin >> d[_n].id;
		cout << "Enter bar id: ";
		cin >> d[_n].barId;
		cout << "Enter drink name: ";
		cin >> d[_n].name;
		SavingDataDrink(d, n, "Input_drink.txt");
		//system("cls");
		cout << "Data was change";
	}
	else cout << "Uncorect nuber";

}

void DeleteDataDrink(Drink* (&d), int& n) {
	int _n;

	cout << "Enter element from 1 to " << n << ": ";
	cin >> _n;
	_n--;

	//system("cls");

	if (_n >= 0 && _n < n) {
		Drink* buf = new Drink[n];

		CopyDrink(buf, d, n);

		--n;
		d = new Drink[n];

		int q = 0;

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				if (i < _n) {
					d[q] = buf[i];
					++q;
				}
				if (i > _n)
				{
					d[q] = buf[i];
					d[q].id = q + 2;
					++q;
				}
			}
			//cout << n << endl;
			//cout << q << " ";
		}

		SavingDataDrink(d, n, "Input_drink.txt");
		//system("cls");
		delete[]buf;
		cout << "Data was deleted";
	}
	else cout << "Wrong number" << endl;
}

void CopyDrink(Drink* (&d_n), Drink* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void CopyDrink(Drink& d_n, Drink& d_o) {
	d_n.id = d_o.id;
	d_n.barId = d_o.barId;
	d_n.name = d_o.name;
}

void AddDateDrink(Drink* (&d), int& n) {
	Drink* buf;
	buf = new Drink[n];

	CopyDrink(buf, d, n);

	n++;
	d = new Drink[n];

	CopyDrink(d, buf, --n);

	cout << "Add bar id and name of drink: " << endl;
	//cout << "Enter id: "; cin >> d[n].id;
	d[n].id = buf[n-1].id+1;
	cout << "Enter bar id: "; cin >> d[n].barId;
	cout << "Enter name: "; cin >> d[n].name;
	SavingDataDrink(d, n+1, "Input_drink.txt");
	//system("cls");

	cout << "Data was addet";

	delete[] buf;
}

void DataSortingDrink(Drink* d, int n) {
	Drink buf;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (d[i].name > d[j].name) {
				CopyDrink(buf, d[j]);
				CopyDrink(d[j], d[i]);
				CopyDrink(d[i], buf);
			}
		}
	}

	cout << "Data was sor" << endl;
}

void SavingDataDrink(Drink* d, int n, string fileName) {
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i].id << endl;
			record << d[i].barId << endl;
			if (i < n - 1)
				record << d[i].name << endl;
			else
				record << d[i].name << endl;
		}
	}
	else
		cout << "write error" << endl;

	record.close();
}

void ccount(Drink* d, int n) {
	int a = 0;
	int f = 0;
	cout << "enter bar id:";
	cin >> a;
	for (int i = 0; i < n; i++) {
		if (a == d[i].barId) {
			cout << "Drink - " << d[i].name << ", with id - " << d[i].id << ", refers to bar id - " << d[i].barId << endl;
			cout << "______________________" << endl;
			f++;
		}
	}
	if (f == 0) cout << "no drinks belong to this bar id" << endl;
}