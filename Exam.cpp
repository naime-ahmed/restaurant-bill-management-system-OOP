#include<bits/stdc++.h>
using namespace std;

// Task 01
class Restaurant{
    public:
        int *foodItemCodes;
        string *foodItemNames;
        int *foodItemPrice;
        double totalTax;

        Restaurant(int foodsQuantity){
            this->foodItemCodes = new int[foodsQuantity];
            this->foodItemNames = new string[foodsQuantity];
            this->foodItemPrice = new int[foodsQuantity];
            this->totalTax = 0;
        }

        int findFood(int code, int numberOfFood){
            for (int i = 0; i < numberOfFood; i++)
            {
                if (this->foodItemCodes[i]==code)
                {
                    return i;
                }
            
            }
            return -1;
            
        }
    
};


// Task 02
void getFoods(int foodsNumber, Restaurant *foods){

    for (int i = 0; i < foodsNumber; i++)
    {
        cin>>foods->foodItemCodes[i];
        getchar();
        getline(cin, foods->foodItemNames[i]);
        cin>>foods->foodItemPrice[i];

    }
    
}

// Task 03
void showFoods(int foodsNumber, Restaurant *foods){

    cout<<"\n\n";
    cout<<"\t\t\t"<<"Make Bill"<<endl;
    cout<<"\t\t"<<"-------------------------"<<endl;
    cout<<"\n\n";
    cout<<"Item Code"<<"\t\t"<<"Item Name"<<"\t\t"<<"Item Price"<<endl;

    for (int i = 0; i < foodsNumber; i++)
    {
        cout<<foods->foodItemCodes[i]<<"\t\t"<<foods->foodItemNames[i]<<"\t\t"<<foods->foodItemPrice[i]<<endl;
    }
    
}

// task 04 to 08
void orderAndSummary(int foodsNumber, Restaurant *foods){

    int boss = 25;

    int tableNumber;
    cout<<"Enter Table No: ";
    cin>>tableNumber;
    int orderQuantity;
    cout<<"Enter Number of Items: ";
    cin>>orderQuantity;

    int storeOrderedItemCode[orderQuantity];
    int storeOrderedItemQuantity[orderQuantity];


    for (int i = 0; i < orderQuantity; i++)
    {
        int code;
        cout<<"Enter Item "<<i+1<<" Code: ";
        handleCode:
        cin>>code;
        if (foods->findFood(code, foodsNumber) == -1)
        {
            cout<<"Invalid code, please Enter correct code: ";
            goto handleCode;
        }
        
        storeOrderedItemCode[i]=code;

        int quantity;
        cout<<"Enter Item "<<i+1<<" Quantity: ";
        cin>>quantity;
        storeOrderedItemQuantity[i]=quantity;
    }

    cout<<"\n\n";
    cout<< setw(50)<<right<<"BILL SUMMARY"<<endl;
    cout<<setw(60)<<right<<"-------------------------"<<endl;
    cout<<"\n\n";
    cout<<"Table No. :"<<tableNumber<<endl;

    cout<<setw(boss)<<left<<"Item Code"<<setw(boss)<<left<<"Item Name"<<setw(boss)<<left<<"Item Price"<<setw(boss)<<left<<"Item Quantity"<<"Total Price"<<endl;

    int totalBill = 0;
    for (int i = 0; i < orderQuantity; i++)
    {
        int foodIndex = foods->findFood(storeOrderedItemCode[i], foodsNumber);

        int foodPrice = foods->foodItemPrice[foodIndex];
        int total = foodPrice * storeOrderedItemQuantity[i];


        totalBill+=total;

        cout<<setw(boss)<<left<<storeOrderedItemCode[i];
        cout<<setw(boss)<<left<< foods->foodItemNames[foods->findFood(storeOrderedItemCode[i], foodsNumber)];
        cout<<setw(boss)<<left<<foodPrice;
        cout<<setw(boss)<<left<< storeOrderedItemQuantity[i];
        cout<<total<<endl;
    }

    cout<<setw(boss*4)<<left<<"TAX"<< fixed<<setprecision(2)<<double((totalBill*5))/100.0 <<endl;

    double tax = double((totalBill*5))/100.0;
    foods->totalTax += double((totalBill*5))/100.0;
    for (int i = 0; i < (boss*4)+10; i++)
    {
        cout<<"_";
    }
    cout<<endl;
    cout<<setw(boss*4)<<left<<"NET TOTAL"<< fixed<<setprecision(2)<< double(totalBill+tax)<<" Taka"<<endl;
    

}

int main(){

    int foods;
    cin>>foods;

    Restaurant mcdonald(foods);

    getFoods(foods, &mcdonald);

    char exit;
    while (exit != 'X')
    {
        showFoods(foods, &mcdonald);

        orderAndSummary(foods, &mcdonald);

        cout<<"Is there any customer? If no, press capital 'X' or press any letter to continue: ";
        cin>>exit;
    }

    // cout<<mcdonald.totalTax;

    return 0;

}