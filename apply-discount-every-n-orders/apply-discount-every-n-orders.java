class Cashier {
    
    private int _count = 0;
    private int _n;
    private int _discount;
    private HashMap<Integer, Integer> _productPrices;

    public Cashier(int n, int discount, int[] products, int[] prices) {
        
        _n = n;
        _discount = discount;
        
        _productPrices = new HashMap<>();
        
        for (int i = 0; i < products.length; ++i) {
            
            _productPrices.put(products[i], prices[i]);
        }
    }
    
    public double getBill(int[] product, int[] amount) {
        
        ++_count;
        
        double bill = 0.0;
        
        for (int i = 0; i < product.length; ++i) {
            
            bill += _productPrices.get(product[i]) * amount[i];
        }
        
        if (_count == _n) {
            
            _count = 0;
            bill *= (100 - _discount) / 100.0;
            
        }
        
        return bill;
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */