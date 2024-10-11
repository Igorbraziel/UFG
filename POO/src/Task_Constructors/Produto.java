package Task_Constructors;

public class Produto {
    private int sequentialCode;
    private String productName;
    private int quantity;
    private String productType;
    private double productValue;

    public Produto(int code){
        this.sequentialCode = code;
    }

    public Produto(int code, String productName){
        this.sequentialCode = code;
        this.productName = productName;
    }

    public Produto(int code, String productName, int quantity){
        this.sequentialCode = code;
        this.productName = productName;
        this.quantity = quantity;
    }

    public Produto(int code, String productName, int quantity, String productType, double productValue){
        this.sequentialCode = code;
        this.productName = productName;
        this.quantity = quantity;
        this.productType = productType;
        this.productValue = productValue;        
    }

    public void vender(int quantity){
        if(this.quantity >= quantity){
            this.quantity -= quantity;
            double totalSaleValue = quantity * this.productValue;
            System.out.println("Valor total da venda: " +  totalSaleValue);
        } else {
            System.out.println("Quantidade não disponível no estoque");
        }
    }

    public void comprar(int quantity, double newValue){
        this.quantity += quantity;
        this.productValue = newValue;
    }

    public void comprar(int quantity){
        this.quantity += quantity;
    }

    public String toString(){
        return "Código do produto: " + sequentialCode + "\n" +
        "Nome do produto: " + productName + "\n" +
        "Quantidade em estoque: " + quantity + "\n" +
        "Tipo do produto: " + productType + "\n" +
        "Valor do produto: " + productValue + "\n";
    }

    public void inserir(String name, int quantity, String productType, double value){
        this.productName = name;
        this.quantity = quantity;
        this.productType = productType;
        this.productValue = value;        
    }

    public boolean igual(Produto product){
        if(this.productName == null || this.productType == null || product.productName == null || product.productType == null){
            return false;
        }

        if(this.productName.equals(product.productName) && this.productType.equals(product.productType)){
            return true;
        } else {
            return false;
        }
    }
}