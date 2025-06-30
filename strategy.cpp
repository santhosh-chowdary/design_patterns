#include<iostream>
#include<vector>
#include<memory>
using namespace std;


class PaymentStrategy{
    public:
        virtual void pay(int amount) const = 0;
        virtual ~PaymentStrategy(){}
};

class CreditCard:public PaymentStrategy{
    public:
        void pay(int amount) const override{
            cout << "Paying " << amount << " using Cretid Card." << endl;
        }
};

class Paypal:public PaymentStrategy{
    public:
        void pay(int amount) const override{
            cout << "Paying " << amount << " using Paypal." << endl;
        }
};

class Bitcoin:public PaymentStrategy{
    public:
        void pay(int amount) const override{
            cout << "Paying " << amount << " using Bitcoin." << endl;
        }
};


class PaymentFactory{
    public:
        static unique_ptr<PaymentStrategy> createPaymentStrategy(const string& Type){
            if (Type == "CreditCard"){
                return make_unique<CreditCard>();
            } else if (Type == "Paypal") {
                return make_unique<Paypal>();
            } else if (Type == "Bitcoin") {
                return make_unique<Bitcoin>();
            } else return nullptr;
        } 
};

class ShoppingCart{
    private:
        unique_ptr<PaymentStrategy> paymentStrategy;
    public:
        void setPaymentStrategy(const string& paymentType){
            paymentStrategy = PaymentFactory::createPaymentStrategy(paymentType);
        }
        
        void checkout(int amount) const{
            if (paymentStrategy){
                paymentStrategy->pay(amount);
            } else {
                cout << "No Payment Strategy Selected." << endl;
            }
        }
};


// Step 4: Client Code
int main() {
    ShoppingCart cart;

    // Use Credit Card Payment
    cart.setPaymentStrategy("CreditCard");
    cart.checkout(100);

    // Use PayPal Payment
    cart.setPaymentStrategy("Paypal");
    cart.checkout(50);

    // Use Bitcoin Payment
    cart.setPaymentStrategy("Bitcoin");
    cart.checkout(200);

    return 0;
}