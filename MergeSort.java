import java.util.Arrays;
/**
 * @author Kolpakov
 * @see java.util.Arrays
 */

public class MergeSort {

	public static void main(String[] args) {
		/**
		 * Implements merge sort
		 * @param args
		 */

		try{
			int [] a = new int[100]; 
			for(int i = 0; i < a.length; i++) {
				a[i] = (int) (Math.random()*100);
			}
			System.out.println("Unsorted:"); 
			for(int i = 0; i < a.length; i++) {
				System.out.print(a[i] + " ");
			}
			MyMergeSort(a, 0, a.length-1);
			System.out.println("\n\nSorted:");
			for(int i = 0; i < a.length; i++) {
				System.out.print(a[i] + " ");
			}
		}
	    catch (NullPointerException e) {
	        System.out.println("Error");
	    }
	}
	/**
	 * 
	 * @param a double array
	 * @param lo bottom line
	 * @param hi upper line
	 */

	private static void MyMergeSort(int[] a, int lo, int hi) { 

		if (hi <= lo)
			return;
		int mid = lo + (hi - lo) / 2; 
		MyMergeSort(a, lo, mid); 
		MyMergeSort(a, mid + 1, hi); 

		int[] buf = Arrays.copyOf(a, a.length); 

		for (int k = lo; k <= hi; k++) 
			buf[k] = a[k];

		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; k++) { 

			if (i > mid) { 
				a[k] = buf[j];
				j++; 
			} else if (j > hi) { 
				a[k] = buf[i];
				i++; 
			} else if (buf[j] < buf[i]) { 
				a[k] = buf[j];
				j++; 
			} else {
				a[k] = buf[i];
				i++;
			}
		}
	}
}
