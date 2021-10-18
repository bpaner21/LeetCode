class Cashier {
private:
    
    int _count = 0;
    int _n = 0;
    int _discount = 0;
    unordered_map<int, int> _productPrices {};
    
public:
    Cashier(int& n, int& discount, vector<int>& products, vector<int>& prices) {
        
        _n = n;
        _discount = discount;
        
        for (int i = 0; i < products.size(); ++i) {
            
            _productPrices[products[i]] = prices[i];
        }
    }
    
    double getBill(const vector<int>& product, const vector<int>& amount) {
        
        ++_count;
        
        double bill = 0.0;
        
        for (int i = 0; i < product.size(); ++i) {
            
            bill += _productPrices[product[i]] * amount[i];
        }
        
        if (_count == _n) {
            
            _count = 0;
            bill *= (100 - _discount) / 100.0;
        }
        
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */