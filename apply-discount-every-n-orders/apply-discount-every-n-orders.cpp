class Cashier {
private:
    
    short int _count = 0;
    short int _n = 0;
    short int _discount = 0;
    unordered_map<short int, short int> _productPrices {};
    
public:
    Cashier(int n, int discount, const vector<int>& products, const vector<int>& prices) : _n(n), _discount(discount) {
        
        for (short int i = 0; i < products.size(); ++i) {
            
            _productPrices.emplace(products[i], prices[i]);
        }
    }
    
    double getBill(const vector<int>& product, const vector<int>& amount) {
        
        ++_count;
        
        double discount = (_count % _n == 0) ? (100.0 - _discount) / 100.0 : 1.0;
        
        double bill = 0.0;
        
        for (int i = 0; i < product.size(); ++i) {
            
            bill += _productPrices[product[i]] * amount[i];
        }
        
        return bill * discount;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */