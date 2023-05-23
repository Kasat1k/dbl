#include "func_bar.h"

void DataEntryBar(Bar* (&d), int& n) {
	cout << "Enter data acount";
	cin >> n;

	d = new Bar[n];

	for (int i = 0; i < n; i++) {
		cout << "Enter id :";
		cin >> d[i].id;
		cout << "Name: ";
		cin >> d[i].name;



		cout << "___________________________________" << endl;
	}
}

void ReadingDataBar(Bar* (&d), int& n, string foleName) {
	ifstream reading(foleName);
	if (reading) {
		reading >> n;
		d = new Bar[n];

		for (int i = 0; i <n; i++) {
			reading >> d[i].id;
			reading >> d[i].name;

		}
	}
	else {
		cout << "Error with open file";
	}

	reading.close();
}

void PrintBar(Bar* d, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Bar: #" << i + 1 << ":" << endl;

		cout << "Id and name of bar:\n" << 
			"Id: " << d[i].id << 
			"\nName: " << d[i].name << endl;

		cout << "______________________" << endl;
	}
}

void DataChangeBar(Bar* (&d), int n) {
	int _n;

	cout << "Enter number of bar: ";
	cin >> _n;
	_n--;

	

	if (_n >= 0 && _n < n) {
		//cout << "Enter id: ";
		//cin >> 
		//d[_n].id;
		cout << "Enter name of bar: ";
		cin >> d[_n].name;
		SavingDataBar(d, n, "Input_bar.txt");
		
		cout << "Data was change";
		//system("cls");
	}
	else cout << "Uncorect nuber";

}

void DeleteDataBar(Bar* (&d), int& n) {
	int _n;

	cout << "Enter element from 1 to " << n << ": ";
	cin >> _n;
	_n--;

	//system("cls");

	if (_n >= 0 && _n < n) {
		Bar* buf = new Bar[n];

		CopyBar(buf, d, n);

		--n;
		d = new Bar[n];

		int q = 0;

		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				if (i < _n) {
					d[q] = buf[i];
					++q;
				}
				if(i>_n)
				{
					d[q] = buf[i];
					d[q].id = q+2;
					++q;
				}
			}
			//cout << n << endl;
			//cout << q << " ";
		}
		cout << endl;
		SavingDataBar(d, n, "Input_bar.txt");
		//system("cls");
		delete[]buf;
		cout << "Data was deleted";
	}
	else cout << "Wrong number" << endl;
}

void CopyBar(Bar* (&d_n), Bar* (&d_o), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_o[i];
	}
}

void CopyBar(Bar& d_n, Bar& d_o) {
	d_n.id = d_o.id;
	d_n.name = d_o.name;
}

void AddDateBar(Bar* (&d), int& n) {
	Bar* buf;
	buf = new Bar[n];

	CopyBar(buf, d, n);

	n++;
	d = new Bar[n];

	CopyBar(d, buf, --n);

	cout << "Add  name of a new bar: " << endl;
	//cout << "Enter id: ";
	d[n].id = buf[n - 1].id + 1;
	cout << "Enter name: "; cin >> d[n].name;
	SavingDataBar(d, n + 1, "Input_bar.txt");
	

	cout << "Data was addet";

	delete[] buf;
}


void SavingDataBar(Bar* d, int n, string fileName) {
	ofstream record(fileName, ios::out);

	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++) {
			record << d[i].id << endl;
			
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
