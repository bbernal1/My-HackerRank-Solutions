//URL for problem:
//https://www.hackerrank.com/challenges/stockmax/problem

#include <bits/stdc++.h>

using namespace std;
vector<string> split_string(string);

//My solution for the function required
long stockmax(vector<int> prices) {

	/*Traverse the array backwards.
	Initialize the maximum stock price so far as the last element in the array
	the loop starts at the last array element
	At the start of each iteration, check the stock price on the day before
	If the price is less than or equal to the Max Price encountered, simple buy the stock
	and keep count of how many stocks bought.
	Once a price that is greater than the max price is encountered OR the array index is at the
	second element (i==1), Calculate the profit obtained
	from selling all of the bought stocks at the previous max price.
	Set a new max price and repeat the procedure.
	Loop terminates at the second element of the array as the price for the day before is always    examined */

	long stockCount = 0;
	long costs = 0;
	long profit = 0;
	long maxPrice = prices[prices.size() - 1];
	for (int i = prices.size() - 1; i >= 1; --i) {
		if (prices[i - 1] <= maxPrice) {
			costs += prices[i - 1];
			++stockCount;
			if (i == 1) {
				profit += maxPrice * stockCount - costs;
			}
		}
		else {
			profit += maxPrice * stockCount - costs;
			costs = 0;
			stockCount = 0;
			maxPrice = prices[i - 1];
		}
	}
	return profit;
}


int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	int t;
	cin >> t;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int t_itr = 0; t_itr < t; t_itr++) {
		int n;
		cin >> n;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		string prices_temp_temp;
		getline(cin, prices_temp_temp);

		vector<string> prices_temp = split_string(prices_temp_temp);

		vector<int> prices(n);

		for (int i = 0; i < n; i++) {
			int prices_item = stoi(prices_temp[i]);

			prices[i] = prices_item;
		}

		long result = stockmax(prices);

		fout << result << "\n";
	}

	fout.close();

	return 0;
}

vector<string> split_string(string input_string) {
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		return x == y and x == ' ';
	});

	input_string.erase(new_end, input_string.end());

	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}

	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}
