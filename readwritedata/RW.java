import java.io.*;
import java.nio.*;


public class RW {
	
	/* Instance Variables */
	private int num0, num1;

	/* Constructor */
	public RW(int _n, int _m) {
		this.num0 = _n;
		this.num1 = _m;
	}
	
	/* Other Methods */
	
	public int getInt() {
		return this.num0;
	}

	public void setInt(int _n) {
		this.num0 = _n;
	}

	public int[] readInt(RandomAccessFile _filename, int _offset) {

		int[] output = {0, 0};

		/* Seek to offset */
		try {
			_filename.seek((long) (_offset));
		} catch (IOException e) {
			e.printStackTrace();
		}

		/* Create byte array to hold read-in data */
		byte[] bfr = new byte[8];

		/* Read in data from disk */
		try {
			_filename.read(bfr);
		} catch (IOException e) {
			e.printStackTrace();
		}

		/* Convert byte array to ByteBuffer to pull data into TreeObjs */
		ByteBuffer rbfr = ByteBuffer.wrap(bfr);

		/* Read in metadata from ByteBuffer */
		output[0] = rbfr.getInt();
		output[1] = rbfr.getInt();

		return output;
	}

	public void writeInt(RandomAccessFile _filename, int _offset) {

		/* Create a byte array and convert to ByteBuffer to insert byte data */
		byte[] bfr = new byte[8];
		ByteBuffer wbfr = ByteBuffer.wrap(bfr);
		int index = 0;

		/* Write metadata */
		wbfr.putInt(index, this.num0);
		index += 4;
		wbfr.putInt(index, this.num1);

		/* Seek to offset */
		try {
			_filename.seek((long) _offset);
		} catch (IOException e) {
			e.printStackTrace();
		}

		/* Getting data from ByteBuffer into a new byte array */
		byte[] writebfr = new byte[8];
		wbfr.get(writebfr, 0, writebfr.length);

		/* Write the data to disk */
		try {
			_filename.write(writebfr);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
