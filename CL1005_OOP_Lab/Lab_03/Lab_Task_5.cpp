#include <iostream>
#include <string>

using namespace std;

class GroceryStore {
    private:
        string items[100] = {""};
        float prices[100] = {-1.0};
        int tracker = 0;

    public:
        GroceryStore() {
            for (int i=0; i<100; i++) {
                prices[i] = -1;
            }
        }
        
        void addItem(string item, float price) {
            for (int i=0; i<100; i++) {
                if (prices[i] == -1) {
                    items[i] = item;
                    prices[i] = price;
                    break;
                }
            }
        }

        void updatePrice(string item, float price) {
            for (int i=0; i<100; i++) {
                if (items[i] == item) {
                    prices[i] = price;
                    break;
                }
            }
        }

        void deleteItem(string item) {
            for (int i=0; i<100; i++) {
                if (items[i] == item) {
                    prices[i] = -1;
                    break;
                }
            }
        }

        pair<float, int> viewInventory(int p = 1) {
            int count = 1;
            float total = 0;
            if (p) {
                cout << "Zainab's Inventory" << endl;
            } else {
                cout << "Customer Invoice" << endl;
            }
            for (int i=0; i<100; i++) {
                if (prices[i] != -1) {
                    cout << endl << "Item " << count << ":" << endl;
                    cout << "Name: " << items[i] << endl;
                    cout << "Price: " << prices[i] << endl;
                    total += prices[i];
                    count++;
                }
            }
            return {total, count-1};
        }

        void generateReceipt() {
            float total;
            int count;
            auto ans = viewInventory(0);
            total = ans.first;
            count = ans.second;
            cout << endl;
            cout << "Total Items = " << count << endl;
            cout << "Total Price = " << total << endl;
        }
};

int main() {
    GroceryStore gs;
    gs.addItem("Apple", 2);
    gs.addItem("Orange", 5);
    gs.addItem("Plastic Water Bottle", 7);
    gs.generateReceipt();
    return 0;
}