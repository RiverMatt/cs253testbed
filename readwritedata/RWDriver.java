import java.io.*;
import java.nio.*;

public class RWDriver {
	public static void main(String[] args) {
		File file = new File("testfile");
		RandomAccessFile rafile;
		int[] value = {0, 0};
		try {
			rafile = new RandomAccessFile(file, "rw");
			RW rw = new RW(10, 11);

			rw.writeInt(rafile, 0);

			value = rw.readInt(rafile, 0);
		try {
			rafile.close();
			file.deleteOnExit();
		} catch (IOException e) {
			e.printStackTrace();
		}
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		System.out.println(value[0] + " " + value[1]);
	}
}
