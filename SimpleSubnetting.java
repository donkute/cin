import java.util.Scanner;
public class SimpleSubnetting {
 // Method to convert CIDR to Subnet Mask
 public static String getSubnetMask(int cidr) {
 int mask = 0xffffffff << (32 - cidr);
 int octet1 = (mask >>> 24) & 0xff;
 int octet2 = (mask >>> 16) & 0xff;
 int octet3 = (mask >>> 8) & 0xff;
 int octet4 = mask & 0xff;
 return octet1 + "." + octet2 + "." + octet3 + "." + octet4;
 }
 public static void main(String[] args) {
 Scanner scanner = new Scanner(System.in);
 System.out.print("Enter CIDR value (e.g. 24): ");
 int cidr = scanner.nextInt();
 if (cidr < 0 || cidr > 32) {
 System.out.println("Invalid CIDR. Please enter a value between 0 and 32.");
 } else {
 String subnetMask = getSubnetMask(cidr);
 System.out.println("Subnet Mask for /" + cidr + " is: " + subnetMask);
 }
 scanner.close();
 }
}
