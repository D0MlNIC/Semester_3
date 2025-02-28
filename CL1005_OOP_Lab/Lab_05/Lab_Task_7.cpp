#include <iostream>
#include <string>

using namespace std;

class Product {
    private:
        string name;
        int id;
        static int idd;
        float price;

    public:
        Product() {
            idd++;
            id = idd;
        }

        Product(string name, float price) : name(name), price(price) {
            idd++;
            id = idd;
        }

        string getName() {
            return this->name;
        }

    
        void setName(string name) {
            this->name = name;
        }

    
        int getId() {
            return this->id;
        }

    
        void setId(int id) {
            this->id = id;
        }

    
        float getPrice() {
            return this->price;
        }

    
        void setPrice(float price) {
            this->price = price;
        }
};

class Inventory {
    private:
        string name;
        int count;
        int numProducts;
        Product **products;

    public:
        Inventory() {}
        Inventory(string name, int numProducts) : name(name), numProducts(numProducts) {
            products = new Product*[numProducts];
            count = 0;
        }

        void addProduct(string name, float price) {
            if (count < numProducts) {
                products[count] = new Product(name, price);
                // products[count].setName(name);
                // products[count].setPrice(price);
                count++;
                cout << "Product Added Succesfully" << endl;
            } else {
                cout << "Not Enough Space in Inventory" << endl;
            }
        }

        void sortInventory() {
            for (int i=0; i<count-1; i++) {
                for (int j=0; j<count-i-1; j++) {
                    if (products[j]->getPrice() > products[j+1]->getPrice()) {
                        Product *p1 = products[j];
                        products[j] = products[j+1];
                        products[j+1] = p1;
                    }
                }
            }
            cout << "Inventory Sorted Successfully" << endl;
        }

        void searchProduct(string name) {
            for (int i=0; i<numProducts; i++) {
                if (products[i]->getName() == name) {
                    cout << "Product Found" << endl;
                    cout << "Product Name: " << name << endl;
                    cout << "Product ID: " << products[i]->getId() << endl;
                    cout << "Product Price: " << products[i]->getPrice() << endl;
                    cout << endl;
                    return;
                }
            }
            cout << "Product Not Found" << endl;
        }

        void displayInventory() {
            for (int i=0; i<numProducts; i++) {
                cout << "Product Name: " << products[i]->getName() << endl;
                cout << "Product ID: " << products[i]->getId() << endl;
                cout << "Product Price: " << products[i]->getPrice() << endl;
                cout << endl;
            }
        }

        ~Inventory() {
            for (int i=0; i<count; i++) {
                delete products[i];
            }
            delete[] products;
        }
};

int Product::idd = 0;

int main() {
    Inventory imtiaz("Imtiaz", 3);
    imtiaz.addProduct("Apple", 15);
    imtiaz.addProduct("Chocolate Cake", 10);
    imtiaz.addProduct("Biscuits", 5);
    cout << "Before Sorting Inventory\n";
    imtiaz.displayInventory();
    cout << "After Sorting Inventory\n";
    imtiaz.sortInventory();
    imtiaz.displayInventory();
    cout << "\nFinding Product...\n";
    imtiaz.searchProduct("Chocolate Cake");
}