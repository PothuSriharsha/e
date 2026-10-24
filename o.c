## CNS Lab — All 11 Questions

I'll provide each question with only the Question, Code, and Output, following your original lab list.

### Question 1: XOR each character with 0

Code (C)

```
#include <stdio.h>

int main()
{
    char s[100];
    int i;

    printf("Enter text: ");
    scanf(" %99[^\n]", s);

    for(i = 0; s[i] != '\0'; i++)
        printf("%c", s[i] ^ 0);

    return 0;
}
```

Output

```
Enter text: Hello world
Hello world
```

### Question 2: Perform AND, OR and XOR operations with 127

Code (C)

```
#include <stdio.h>

int main()
{
    char s[100];
    int i;

    printf("Enter text: ");
    scanf(" %99[^\n]", s);

    printf("AND: ");
    for(i = 0; s[i] != '\0'; i++)
        printf("%c", s[i] & 127);

    printf("\nOR: ");
    for(i = 0; s[i] != '\0'; i++)
        printf("%c", s[i] | 127);

    printf("\nXOR: ");
    for(i = 0; s[i] != '\0'; i++)
        printf("%c", s[i] ^ 127);

    return 0;
}
```

Output

```
Enter text: Hello world
AND: Hello world
OR: 
XOR: 7_
```

Note: OR and XOR may display non-printable characters differently depending on the terminal.

### Question 3: Implement Caesar cipher, substitution cipher and Hill cipher

This question contains three programs.

3(a) Caesar Cipher — Java

```
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter uppercase text: ");
        String s = sc.nextLine();

        System.out.print("Enter key: ");
        int key = sc.nextInt();

        String enc = "", dec = "";

        for (int i = 0; i < s.length(); i++)
            enc += (char)((s.charAt(i) - 'A' + key) % 26 + 'A');

        for (int i = 0; i < enc.length(); i++)
            dec += (char)((enc.charAt(i) - 'A' - key + 26) % 26 + 'A');

        System.out.println("Encrypted: " + enc);
        System.out.println("Decrypted: " + dec);

        sc.close();
    }
}
```

Output

```
Enter uppercase text: ABC
Enter key: 3
Encrypted: DEF
Decrypted: ABC
```

3(b) Substitution Cipher — Java

```
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String a = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        String b = "QWERTYUIOPASDFGHJKLZXCVBNM";

        System.out.print("Enter uppercase text: ");
        String s = sc.nextLine();

        String enc = "", dec = "";

        for (int i = 0; i < s.length(); i++)
            enc += b.charAt(a.indexOf(s.charAt(i)));

        for (int i = 0; i < enc.length(); i++)
            dec += a.charAt(b.indexOf(enc.charAt(i)));

        System.out.println("Encrypted: " + enc);
        System.out.println("Decrypted: " + dec);

        sc.close();
    }
}
```

Output

```
Enter uppercase text: ABC
Encrypted: QWE
Decrypted: ABC
```

3(c) Hill Cipher — Java

```
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter two uppercase letters: ");
        String s = sc.nextLine().toUpperCase();

        int a = s.charAt(0) - 'A';
        int b = s.charAt(1) - 'A';

        int x = (3 * a + 3 * b) % 26;
        int y = (2 * a + 5 * b) % 26;

        String enc = "" + (char)(x + 'A') + (char)(y + 'A');

        int p = (15 * x + 17 * y) % 26;
        int q = (20 * x + 9 * y) % 26;

        String dec = "" + (char)(p + 'A') + (char)(q + 'A');

        System.out.println("Encrypted: " + enc);
        System.out.println("Decrypted: " + dec);

        sc.close();
    }
}
```

Output

```
Enter two uppercase letters: HI
Encrypted: TC
Decrypted: HI
```

### Question 4: Implement DES algorithm

Code (Java)

```
import java.util.Scanner;
import javax.crypto.*;

class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine();

        KeyGenerator kg = KeyGenerator.getInstance("DES");
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("DES");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(s.getBytes());

        System.out.println("Encrypted successfully");

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(enc);

        System.out.println("Decrypted: " + new String(dec));

        sc.close();
    }
}
```

Output

```
Enter text: Hello
Encrypted successfully
Decrypted: Hello
```

### Question 5: Implement Blowfish algorithm

Code (Java)

```
import java.util.Scanner;
import javax.crypto.*;

class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine();

        KeyGenerator kg = KeyGenerator.getInstance("Blowfish");
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("Blowfish");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(s.getBytes());

        System.out.println("Encrypted successfully");

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(enc);

        System.out.println("Decrypted: " + new String(dec));

        sc.close();
    }
}
```

Output

```
Enter text: Hello
Encrypted successfully
Decrypted: Hello
```

### Question 6: Implement Rijndael (AES) algorithm

Code (Java)

```
import java.util.Scanner;
import javax.crypto.*;

class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine();

        KeyGenerator kg = KeyGenerator.getInstance("AES");
        kg.init(128);

        SecretKey key = kg.generateKey();
        Cipher c = Cipher.getInstance("AES");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(s.getBytes());

        System.out.println("Encrypted successfully");

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(enc);

        System.out.println("Decrypted: " + new String(dec));

        sc.close();
    }
}
```

Output

```
Enter text: Hello
Encrypted successfully
Decrypted: Hello
```

### Question 7: Implement RC4, Blowfish encryption and generate a secret key

7(a) RC4 — Java

```
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String text = sc.nextLine();

        System.out.print("Enter key: ");
        String key = sc.nextLine();

        int[] s = new int[256];

        for (int i = 0; i < 256; i++)
            s[i] = i;

        int j = 0;

        for (int i = 0; i < 256; i++) {
            j = (j + s[i] + key.charAt(i % key.length())) % 256;

            int t = s[i];
            s[i] = s[j];
            s[j] = t;
        }

        int i = 0;
        j = 0;

        String result = "";

        for (int k = 0; k < text.length(); k++) {
            i = (i + 1) % 256;
            j = (j + s[i]) % 256;

            int t = s[i];
            s[i] = s[j];
            s[j] = t;

            int r = s[(s[i] + s[j]) % 256];
            result += (char)(text.charAt(k) ^ r);
        }

        System.out.println("Encrypted text: " + result);
        sc.close();
    }
}
```

Output

```
Enter text: Hello
Enter key: key
Encrypted text: [encrypted characters]
```

7(b) Encrypt “Hello world” using Blowfish — Java

```
import javax.crypto.*;

class Main {
    public static void main(String[] args) throws Exception {
        String s = "Hello world";

        KeyGenerator kg = KeyGenerator.getInstance("Blowfish");
        SecretKey key = kg.generateKey();

        Cipher c = Cipher.getInstance("Blowfish");

        c.init(Cipher.ENCRYPT_MODE, key);
        byte[] enc = c.doFinal(s.getBytes());

        System.out.println("Encrypted successfully");

        c.init(Cipher.DECRYPT_MODE, key);
        byte[] dec = c.doFinal(enc);

        System.out.println("Decrypted: " + new String(dec));
    }
}
```

Output

```
Encrypted successfully
Decrypted: Hello world
```

7(c) Generate a secret key using Java Keytool

Command

```
keytool -genseckey -alias mykey -keyalg Blowfish -keysize 128 -keystore mykeystore.jceks -storetype JCEKS
```

Output

```
Enter keystore password:
Secret key generated successfully.
```

### Question 8: Implement RSA algorithm

Code (Java)

```
import java.util.Scanner;
import java.security.*;
import javax.crypto.*;

class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine();

        KeyPairGenerator kg = KeyPairGenerator.getInstance("RSA");
        kg.initialize(2048);

        KeyPair kp = kg.generateKeyPair();
        Cipher c = Cipher.getInstance("RSA");

        c.init(Cipher.ENCRYPT_MODE, kp.getPublic());
        byte[] enc = c.doFinal(s.getBytes());

        System.out.println("Encrypted successfully");

        c.init(Cipher.DECRYPT_MODE, kp.getPrivate());
        byte[] dec = c.doFinal(enc);

        System.out.println("Decrypted: " + new String(dec));

        sc.close();
    }
}
```

Output

```
Enter text: Hello
Encrypted successfully
Decrypted: Hello
```

### Question 9: Implement Diffie–Hellman key exchange using HTML and JavaScript

Code (HTML + JavaScript)

```
<!DOCTYPE html>
<html>
<body>
<h3>Diffie-Hellman Key Exchange</h3>

Prime p: <input id="p" value="23"><br><br>
Generator g: <input id="g" value="5"><br><br>
Alice private key: <input id="a" value="6"><br><br>
Bob private key: <input id="b" value="15"><br><br>

<button onclick="calculate()">Calculate</button>
<p id="result"></p>

<script>
function calculate() {
    let p = Number(document.getElementById("p").value);
    let g = Number(document.getElementById("g").value);
    let a = Number(document.getElementById("a").value);
    let b = Number(document.getElementById("b").value);

    let A = (g ** a) % p;
    let B = (g ** b) % p;

    let key1 = (B ** a) % p;
    let key2 = (A ** b) % p;

    document.getElementById("result").innerHTML =
        "Alice public key: " + A +
        "<br>Bob public key: " + B +
        "<br>Alice shared key: " + key1 +
        "<br>Bob shared key: " + key2;
}
</script>
</body>
</html>
```

Output

```
Alice public key: 8
Bob public key: 19
Alice shared key: 2
Bob shared key: 2
```

### Question 10: Implement SHA-1 message digest

Code (Java)

```
import java.util.Scanner;
import java.security.MessageDigest;

class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine();

        MessageDigest md = MessageDigest.getInstance("SHA-1");
        byte[] result = md.digest(s.getBytes());

        for (byte b : result)
            System.out.printf("%02x", b & 0xff);

        System.out.println();
        sc.close();
    }
}
```

Output

```
Enter text: Hello
f7ff9e8b7bb2e09b70935a5d785e0cc5d9d0abf0
```

### Question 11: Implement MD5 message digest

Code (Java)

```
import java.util.Scanner;
import java.security.MessageDigest;

class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter text: ");
        String s = sc.nextLine();

        MessageDigest md = MessageDigest.getInstance("MD5");
        byte[] result = md.digest(s.getBytes());

        for (byte b : result)
            System.out.printf("%02x", b & 0xff);

        System.out.println();
        sc.close();
    }
}
```

Output

```
Enter text: Hello
8b1a9953c4611296a827abf8c47804d7
```