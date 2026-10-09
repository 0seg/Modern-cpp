
#include <iostream>
#include <iomanip>
#include <string>
#include <utility>

// Abstract base class: defines the payment interface.
class PaymentMethod {
public:
    virtual bool pay(double amount) const = 0;

    virtual ~PaymentMethod() = default;
};

// Concrete implementation for credit card payments.
class CreditCard : public PaymentMethod {
public:
    explicit CreditCard(std::string lastFourDigits)
        : lastFourDigits_{std::move(lastFourDigits)} {}

    bool pay(double amount) const override {
        std::cout << "Credit card ending in "
                  << lastFourDigits_
                  << ": $" << amount << '\n';

        return true; // Simulates a successful payment.
    }

private:
    std::string lastFourDigits_;
};

// Concrete implementation for PayPal payments.
class PayPal : public PaymentMethod {
public:
    explicit PayPal(std::string email)
        : email_{std::move(email)} {}

    bool pay(double amount) const override {
        std::cout << "PayPal account "
                  << email_
                  << ": $" << amount << '\n';

        return true; // Simulates a successful payment.
    }

private:
    std::string email_;
};

// Processes payments without depending on concrete payment types.
class Checkout {
public:
    void processPayment(
        const PaymentMethod& method,
        double amount
    ) const {
        if (method.pay(amount)) {
            std::cout << "Payment successful.\n\n";
        } else {
            std::cout << "Payment failed.\n\n";
        }
    }
};

int main() {
    std::cout << std::fixed << std::setprecision(2);

    CreditCard card{"4242"};
    PayPal paypal{"customer@example.com"};

    Checkout checkout;

    checkout.processPayment(card, 499.99);
    checkout.processPayment(paypal, 129.50);
}
