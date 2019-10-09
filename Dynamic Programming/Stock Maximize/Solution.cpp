//URL for problem:
//https://www.hackerrank.com/challenges/stockmax/problem

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
