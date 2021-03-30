package com.company;


import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int count = scanner.nextInt();
        int maxSum = 0, sum = 0;
        for (int i = 0; i < count; i++) {
            sum += scanner.nextInt();
            if (sum > maxSum) maxSum = sum;
            if (sum < 0) sum = 0;
        }
        System.out.print(maxSum);
    }
}
