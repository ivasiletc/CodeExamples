import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JList;
import javax.swing.JTextField;
import javax.swing.JTextArea;

public class GUI extends JFrame{
	private JTextField txtName;
	public GUI() {
		getContentPane().setLayout(null);
		
		JScrollPane scrollPane = new JScrollPane();
		scrollPane.setBounds(213, 116, 466, 287);
		getContentPane().add(scrollPane);
		
		JTextArea textArea = new JTextArea();
		scrollPane.setColumnHeaderView(textArea);
		
		JList list = new JList();
		list.setBounds(21, 116, 130, 287);
		getContentPane().add(list);
		
		txtName = new JTextField();
		txtName.setBounds(21, 37, 86, 20);
		txtName.setText("name");
		getContentPane().add(txtName);
		txtName.setColumns(10);
	}
	public static void main(String[] args){
		new GUI();
	}
}
