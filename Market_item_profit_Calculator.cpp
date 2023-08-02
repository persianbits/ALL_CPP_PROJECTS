#include <iostream>

double calculateSellingPrice(double costPrice, double profitPercent) {
    // Calculate the price after profit
    double sellingPrice = costPrice + (costPrice * profitPercent / 100);
    return sellingPrice;
}

int main() {
    double bulkCost, numberOfPieces, profitPercent;

    while (true) {  // Infinite loop
        std::cout << "\nEnter the cost of the bulk item: $";
        std::cin >> bulkCost;

        std::cout << "Enter the number of pieces in that bulk: ";
        std::cin >> numberOfPieces;

        do {
            std::cout << "Enter the desired profit percentage (10% or more): ";
            std::cin >> profitPercent;

            if (profitPercent < 10) {
                std::cout << "Please enter a profit percentage of 10% or more." << std::endl;
            }

        } while (profitPercent < 10);

        double costPerPiece = bulkCost / numberOfPieces;
        double sellingPrice = calculateSellingPrice(costPerPiece, profitPercent);
        
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Cost per piece: $" << costPerPiece << std::endl;
        std::cout << "Selling price per piece after adding profit: $" << sellingPrice << std::endl;
        std::cout << "---------------------------------------" << std::endl; // Separation line for clarity
    }

    return 0;
}


