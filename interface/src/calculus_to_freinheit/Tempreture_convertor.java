package calculus_to_freinheit;

import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;

public class Tempreture_convertor extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	
	JTextField tc = new JTextField();
	JTextField tf = new JTextField();
	
	public Tempreture_convertor() {
		this.setTitle("Tempreture_convertor");
		this.setSize(600, 500);
		this.setLocationRelativeTo(null);
		//this.setLocation(0,0);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setVisible(true);
		
		//you can use more than one layout with other containers(pannel) ot0her than JPannel
		//this.getContentPane().setLayout( (LayoutManager) new FlowLayout(FlowLayout.Container(Center(10, 10))));
		this.getContentPane().setLayout(new FlowLayout(FlowLayout.CENTER));
		
		JLabel lc = new JLabel ("C°: ");
		getContentPane().add(lc);
		
		//JTextField tc = new JTextField();
		getContentPane().add(tc);
		tc.setColumns(10);
		
		JLabel lf = new JLabel ("F°: ");
		getContentPane().add(lf);
		
		getContentPane().add(tf);
		tf.setColumns(10);
		
		JButton b = new JButton("Convert");
		getContentPane().add(b);
		
		pack();
		b.addActionListener((ActionListener) this);
		tf.addKeyListener((KeyListener) this);
	    //		tf.addActionListener((ActionListener) this);
	    
		}

		/*public void bactionPerformed(ActionEvent e) {
			//if (e.getSource().equals("Convert"){
			    
			//if(e.getActionComma.equals("Convert")
					//if(e.getActionComma.equals("Convert")
			if(tf.getText().isBlank()) {
				
					double celcuis_value = Double.parseDouble(tc.getText());
					tf.setText(Double.toString (celcuis_value + 272));
			}

			else if(tc.getText().isBlank()) {
				
					double celcuis_value = Double.parseDouble(tf.getText());
					tc.setText(Double.toString (celcuis_value - 272));
			}
		}*/

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			if(tf.getText().isBlank()) {
				
				if(e.getActionCommand().equals("Convert")){
					double celcuis_value = Double.parseDouble(tc.getText());
					tf.setText(Double.toString (celcuis_value + 272));
				}
			}

			else if(tc.getText().isBlank()) {
				
				if(e.getActionCommand().equals("Convert")){
					double celcuis_value = Double.parseDouble(tf.getText());
					tc.setText(Double.toString (celcuis_value - 272));
				}
			}
		}
}