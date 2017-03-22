package com.example.gourdboy.serialportdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.EditText;

import com.example.gourdboy.serialportdemo.jssc.SerialPort;
import com.example.gourdboy.serialportdemo.jssc.SerialPortEvent;
import com.example.gourdboy.serialportdemo.jssc.SerialPortEventListener;
import com.example.gourdboy.serialportdemo.jssc.SerialPortException;
import com.example.gourdboy.serialportdemo.jssc.SerialPortList;
import com.example.gourdboy.serialportdemo.jssc.SerialUtil;


public class MainActivity extends AppCompatActivity
{

	private SerialPort serialPort1;
	private EditText et;
	private SerialUtil serialUtil;

	@Override
	protected void onCreate(Bundle savedInstanceState)
	{
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		et = (EditText) findViewById(R.id.et);
		/*String[] ports = SerialPortList.getPortNames();
		for (String port : ports)
		{
			et.append(port+"\n");
		}
		serialPort1 = new SerialPort("/dev/ttyS2");
		try
		{
			serialPort1.openPort();
			serialPort1.setParams(SerialPort.BAUDRATE_9600,
					SerialPort.DATABITS_8,
					SerialPort.STOPBITS_1,
					SerialPort.PARITY_NONE);
			serialPort1.writeBytes("This is a test string".getBytes());//Write data to port
			int mask = SerialPort.MASK_RXCHAR + SerialPort.MASK_CTS + SerialPort.MASK_DSR;//Prepare mask
			serialPort1.setEventsMask(mask);//Set mask
			serialPort1.addEventListener(listenr);//Add SerialPortEventListener
		}
		catch (SerialPortException e)
		{
			e.printStackTrace();
		}*/
		serialUtil = SerialUtil.getInstance();
		serialUtil.openPort("/dev/ttyS2",SerialUtil.BAUDRATE_9600,SerialUtil.DATABITS_8,SerialUtil.STOPBITS_1,SerialUtil.PARITY_NONE);
		serialUtil.setDataRecvListener(new SerialUtil.DataRecvListener()
		{
			@Override
			public void doWhenRecvData(final byte[] bytes)
			{
				runOnUiThread(new Runnable()
				{
					@Override
					public void run()
					{
						et.append(new String(bytes)+"\n");
					}
				});
				Log.i("xxxxxxxxx","recv data： "+new String(bytes));
			}
		});
		serialUtil.sendData("hello world".getBytes());
	}

	@Override
	protected void onDestroy()
	{
		super.onDestroy();
		/*try
		{
			serialPort1.closePort();//Close serial port
		}
		catch (SerialPortException e)
		{
			e.printStackTrace();
		}*/
		serialUtil.closePort();
	}

	SerialPortEventListener listenr = new SerialPortEventListener()
	{
		@Override
		public void serialEvent(SerialPortEvent serialPortEvent)
		{

			if (serialPortEvent.isRXCHAR())
			{
				try
				{
					if (serialPortEvent.getEventValue() > 2)
					{
						Log.i("xxxxxxxxx", "come into return  "+serialPortEvent.getEventValue());
						Log.i("xxxxxxxxx", new String(serialPort1.readBytes(serialPortEvent.getEventValue())));
					}
				}
				catch (Exception e)
				{
					e.printStackTrace();
				}

			}
		}
	};
}
