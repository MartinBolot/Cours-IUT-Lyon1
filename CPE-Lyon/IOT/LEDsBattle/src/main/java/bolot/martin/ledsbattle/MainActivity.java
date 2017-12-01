package bolot.martin.ledsbattle;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RadioButton;
import android.widget.TextView;
import android.widget.Toast;

import org.w3c.dom.Text;

import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

import static java.lang.Integer.parseInt;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = (Button) findViewById(R.id.pressButton);
        RadioButton buttonJoueur1 = (RadioButton) findViewById(R.id.radio_joueur1);
        RadioButton buttonJoueur2 = (RadioButton) findViewById(R.id.radio_joueur2);
        EditText addressText = (EditText) findViewById(R.id.address_input);
        EditText portText = (EditText) findViewById(R.id.port_input);

        button.setOnClickListener(new View.OnClickListener()
        {
            public void onClick(View v)
            {
                UDPSend();
            }
        });

        //sélection du joueur
        buttonJoueur1.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v) {
                currentPlayer = PLAYER_1;
            }
        });
        buttonJoueur2.setOnClickListener(new View.OnClickListener(){
            public void onClick(View v) {
                currentPlayer = PLAYER_2;
            }
        });

        addressText.addTextChangedListener(new TextWatcher() {
            @Override
            public void afterTextChanged(Editable s) {}

            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                if(s.length() != 0) {
                    IP = s.toString();
                }
            }
        });

        portText.addTextChangedListener(new TextWatcher() {
            @Override
            public void afterTextChanged(Editable s) {}

            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {}

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                if(s.length() != 0) {
                    port = parseInt(s.toString());
                }
            }
        });
    }

    private void UDPSend() {
    // L'émission est faite depuis un processus, à cause de restriction des
    // API 11 et +
        (new Thread() {
            @Override
            public void run() {

                // définition des outils réseau
                try{
                    address = InetAddress.getByName(IP);
                }
                catch(Exception e) {
                    System.out.println("address " + IP + ": ");
                    System.out.println(e.getMessage());
                }
                try{
                    UDPSocket = new DatagramSocket();
                }
                catch(Exception e) {
                    System.out.println("socket " + port + ", " + address +  " : ");
                    System.out.println(e.getMessage());
                }

                // Pour simplifier l'exemple, nous n'envoyons qu'1 octet
                //byte[] data = new byte[1];
                String joueur = currentPlayer.equals(PLAYER_2) ? "(1)" : "(2)";
                byte[] data = joueur.getBytes();
                //data[0] = Byte.parseByte();
                DatagramPacket packet = new DatagramPacket(data, data.length, address, port);
                try {
                    UDPSocket.send(packet);
                    System.out.println("packet sent");
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }).start();
    }

    private String IP = "192.168.1.30";
    private int port = 10000;
    private InetAddress address;
    private DatagramSocket UDPSocket;
    private final String PLAYER_1 = "Joueur1";
    private final String PLAYER_2 = "Joueur2";
    private String currentPlayer = PLAYER_1;
}
