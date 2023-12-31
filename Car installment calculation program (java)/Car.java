import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.text.NumberFormat;

public class Car extends JFrame{
    public static void main(String args[]){ new Car();}

    private JTextField mTextPrice = new JTextField();
    private JTextField mTextDown = new JTextField();
    private JTextField mTextMonth = new JTextField();
    private JTextField mTextRate = new JTextField();
    private JTextField mTextResult = new JTextField();
    private JRadioButton mRadioBath, mRadioPercent;
    private Font mFont = new Font("Tahoma", Font.PLAIN, 14);
    //PrintStream out = new PrintStream(new File("C:/Users/Mo/Desktop/output.txt"));
    
    public Car(){
        UIManager.put("OptionPane.messageFont" , mFont); // สำหรับ Message Dialog

        setTitle("โปรแกรมคำนวณค่างวดรถ");
        setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setSize(400, 300);
        setResizable(false);
        setLayout(new GridLayout(6, 1));
        
        JPanel p1 = new JPanel();
        p1.add(new JLabel("   ราคารถ "));
        mTextPrice.setPreferredSize(new Dimension(150, 25));
        p1.add(mTextPrice);
        p1.add(new JLabel(" บาท "));
        setFont(p1);
        add(p1);

        JPanel p2 = new JPanel();
        p2.add(new JLabel("              เงินดาวน์ "));
        mTextDown.setPreferredSize(new Dimension(150, 25));
        p2.add(mTextDown);
        mRadioBath = new JRadioButton("บาท");
        mRadioBath.setSelected(true);
        p2.add(mRadioBath);
        mRadioPercent = new JRadioButton("%");
        p2.add(mRadioPercent);
        ButtonGroup group = new ButtonGroup();
        group.add(mRadioBath);
        group.add(mRadioPercent);
        setFont(p2);
        add(p2);

        JPanel p3 = new JPanel();
        p3.add(new JLabel("อัตราดอกเบี้ย "));
        mTextRate.setPreferredSize(new Dimension(150, 25));
        p3.add(mTextRate);
        p3.add(new JLabel(" % ต่อปี "));
        setFont(p3);
        add(p3);

        JPanel p4 = new JPanel();
        p4.add(new JLabel("จำนวนงวด "));
        mTextMonth.setPreferredSize(new Dimension(150, 25));
        p4.add(mTextMonth);
        p4.add(new JLabel(" เดือน "));
        setFont(p4);
        add(p4);

        JPanel p5 = new JPanel();
        p5.add(new JLabel(" "));
        JButton buttonCal = new JButton("คำนวณ");
        buttonCal.addActionListener(e -> calculate());
        p5.add(buttonCal);
        setFont(p5);
        add(p5);


        JPanel p6 = new JPanel();
        p6.add(new JLabel("             ค่างวด "));
        mTextResult.setEnabled(false);
        mTextResult.setDisabledTextColor(Color.RED);
        mTextResult.setPreferredSize(new Dimension(150, 25));
        p6.add(mTextResult);
        p6.add(new JLabel(" บาท / เดือน  "));
        setFont(p6);
        add(p6);

        setVisible(true);

    }

    private int count;
    private double price;
    private double down;
    private double rate;
    private double ratePerMonth ;
    private double finance;
    private int months;
    private double interest ;
    private double total ;
    private double installment ;
    private String result;

    public void setFont(JPanel panel){
        count = panel.getComponentCount();
        for(int i = 0; i< count; i++){
            panel.getComponent(i).setFont(mFont);
        }
    }

    public void calculate(){
        price = parse(mTextPrice);
        if(price <= 0){
            showMessage("ราคารถไม่ถูกต้อง");
            return;
        }

        down = parse(mTextDown);
        if(down <= 0 || down >= price){
            showMessage("เงินดาวน์ไม่ถูกต้อง");
            return;
        }
        
        if(mRadioPercent.isSelected()){
            down = price * (down/100);
        }

        rate = parse(mTextRate);
        if(rate <= 0) {
            showMessage("อัตราดอกเบื้ยไม่ถูกต้อง");
            return;
        }

        ratePerMonth = (rate / 12) / 100;
        finance = price - down;
        months = (int)parse(mTextMonth);
        if(months <= 0){
            showMessage("จำนวนงวดไม่ถูกต้อง");
            return;
        }

        interest = finance * months * ratePerMonth;
        total = finance + interest;
        installment = total / months;

        NumberFormat format = NumberFormat.getNumberInstance();
        result = format.format(installment);
        mTextResult.setText(result);
        try {
            PrintStream out = new PrintStream(new File("C:Desktop/output.txt"));
            out.println("Car Price: "+price+ " Baht "+ "\nDown payment : " +down+ " Baht "+"\nInterest Rate : "+ rate+ " % / Year "+"\nNumber of Installment : " +months+ " Month"+ "\nInstallment : " + installment+" Baht/Month");
            out.close();
            } catch (IOException e) {
            System.err.println("IOException found :" + e.getMessage());}

    }
    public double parse(JTextField textField){
        try {
            return Double.parseDouble(textField.getText().trim());
        }  catch(Exception ex){
            return -1;
        }
    }
    public void showMessage(String msg){
        JOptionPane.showMessageDialog(null, msg);
    }
}
        
