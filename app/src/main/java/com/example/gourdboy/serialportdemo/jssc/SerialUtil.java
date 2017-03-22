package com.example.gourdboy.serialportdemo.jssc;


import android.util.Log;

/**
 * Created by GourdBoy on 2017/3/22.
 */

public class SerialUtil
{
	public static boolean VERBOSE = true;

	public static final int BAUDRATE_110 = 110;
	public static final int BAUDRATE_300 = 300;
	public static final int BAUDRATE_600 = 600;
	public static final int BAUDRATE_1200 = 1200;
	public static final int BAUDRATE_4800 = 4800;
	public static final int BAUDRATE_9600 = 9600;
	public static final int BAUDRATE_14400 = 14400;
	public static final int BAUDRATE_19200 = 19200;
	public static final int BAUDRATE_38400 = 38400;
	public static final int BAUDRATE_57600 = 57600;
	public static final int BAUDRATE_115200 = 115200;
	public static final int BAUDRATE_128000 = 128000;
	public static final int BAUDRATE_256000 = 256000;


	public static final int DATABITS_5 = 5;
	public static final int DATABITS_6 = 6;
	public static final int DATABITS_7 = 7;
	public static final int DATABITS_8 = 8;


	public static final int STOPBITS_1 = 1;
	public static final int STOPBITS_2 = 2;
	public static final int STOPBITS_1_5 = 3;


	public static final int PARITY_NONE = 0;
	public static final int PARITY_ODD = 1;
	public static final int PARITY_EVEN = 2;
	public static final int PARITY_MARK = 3;
	public static final int PARITY_SPACE = 4;

	private SerialPort sp;
	private DataRecvListener listener;
	private static class SerUtilHolder
	{
		public static final SerialUtil su = new SerialUtil();
	}
	private SerialUtil()
	{

	}
	public static SerialUtil getInstance()
	{
		return SerUtilHolder.su;
	}
	public boolean openPort(String port, int baudRate, int dataBits, int stopBits, int parity)
	{
		if(port==null||port.isEmpty())
			return false;
		if(sp==null)
			sp = new SerialPort(port);
		try
		{
			boolean openport = sp.openPort();
			Log.i("xxxxxxxxx","open port："+openport);
			return sp.setParams(baudRate,dataBits,stopBits,parity);
		}
		catch (SerialPortException e)
		{
			e.printStackTrace();
		}
		return false;
	}
	public boolean sendData(byte[] bytes)
	{
		if(sp==null)
		{
			if(VERBOSE)
				System.out.println("please execute the method openPort first");
			return false;
		}
		try
		{
			Log.i("xxxxxxxxx","send Data: "+new String(bytes));
			return sp.writeBytes(bytes);
		}
		catch (SerialPortException e)
		{
			e.printStackTrace();
		}
		if(VERBOSE)
			System.out.println("send data failed");
		return false;
	}
	public void setDataRecvListener(DataRecvListener dataRecvListener)
	{
		listener = dataRecvListener;
		int mask = SerialPort.MASK_RXCHAR + SerialPort.MASK_CTS + SerialPort.MASK_DSR;//Prepare mask
		try
		{
			sp.setEventsMask(mask);//Set mask
			sp.addEventListener(new SerialPortEventListener()
			{
				@Override
				public void serialEvent(SerialPortEvent serialPortEvent)
				{
					if (serialPortEvent.isRXCHAR())
					{
						if (serialPortEvent.getEventValue() > 1)
						{
							Log.i("xxxxxxxxx", "come into return  "+serialPortEvent.getEventValue());
							if (listener != null&&sp!=null)
							{
								try
								{
									listener.doWhenRecvData(sp.readBytes(serialPortEvent.getEventValue()));
								}
								catch (SerialPortException e)
								{
									e.printStackTrace();
								}
							}
						}
					}
				}
			});
		}
		catch (SerialPortException e)
		{
			e.printStackTrace();
		}
	}
	public interface DataRecvListener
	{
		void doWhenRecvData(byte[] bytes);
	}
	public boolean closePort()
	{
		if(sp==null)
		{
			if (VERBOSE)
				System.out.println("please execute the method openPort first");
			return false;
		}
		try
		{
			return sp.closePort();
		}
		catch (SerialPortException e)
		{
			e.printStackTrace();
		}
		return false;
	}
}
