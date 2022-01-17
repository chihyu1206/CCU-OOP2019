#include "Portfolio.h"
#include "Checking.h"
#include "Investment.h"
#include "Savings.h"
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cctype>
Portfolio::Portfolio() { // constructor
  default_size = 50; 
  current_size = 0;
  alist = new Account *[default_size];
  fp = stdin;
}
Portfolio::~Portfolio() { // destructor
  for (int i = 0; i < default_size; i++) {
    delete alist[i];
  }
  fp = NULL;
}
bool Portfolio::importFile(const char *filename) { // function to import file
  int i = 0, j = 0, k = 0; // initialization
  int start = 0, end = 0, input_size = 0, possible_size = 0;
  float f1 = 0.0, f2 = 0.0, f3 = 0.0, f4 = 0.0;
  char input[50], first_name[25], last_name[25], type[15];
  const char *type1 = "Savings", *type2 = "Checking", *type3 = "Investment";
  for (i = 0; i < 50; i++) {
    if (i < 15)
      type[i] = '\0';
    else if (i < 25) {
      first_name[i] = '\0';
      last_name[i] = '\0';
    }
    else {
      input[i] = '\0';
    }
  }
  fp = fopen(filename, "r"); // open the input file
  if (fp) {
    fscanf(fp, "%d\n", &input_size); // scan the number of accounts
    possible_size = current_size + input_size;
    while (possible_size > default_size) { 
      /* if the current size may not endure the upcoming data 
         make the current maximum size be double */
      Account **newlist = new Account *[default_size * 2];
      for (i = 0; i < default_size; i++) {
        newlist[i] = alist[i];
      }
      for (i = 0; i < default_size; i++)
        delete alist[i];
      alist = newlist;
      default_size *= 2;
    } // end dealing with the size problem

    for (j = 0; j < input_size; j++) { // start to scan in each account's info
      if (fgets(input, 50, fp) != NULL) { // begin dealing with the first/last name
        start = 0;
        while (!isalpha(input[start]) && input[start] != '\0')
          start++;
        end = start + 1;
        while (input[end] != ',' && input[end] != '\0') // find the location of comma
          end++;
        end--;
        while (!isalpha(input[end]) && end >= 0) //find the last alpha of the last name
          end--;
        k = 0;
        for (; start <= end; start++, k++)
          last_name[k] = input[start];
        last_name[k] = '\0';
        while (input[end] != ',' && input[end] != '\0') { //find the comma
          end++;
        }
        start = end + 1;
        while (!isalpha(input[start]) && input[start] != '\0')
          start++;
        end = start + 1;
        while (input[end] != '\n')
          end++;                  // the last index
        while (!isalpha(input[end]) && end >= start) //find the last alpha of the last name
          end--;
        k = 0;
        for (; start <= end; start++, k++)
          first_name[k] = input[start];
        first_name[k] = '\0';
      } // end dealing with the first/last name
      fscanf(fp, "%s", type);
      if (!strcmp(type, type1)) {
        alist[current_size] = new Savings;
        alist[current_size]->SetName(first_name, last_name);
        alist[current_size]->SetType(type1);
        fscanf(fp, "%f%f", &f1, &f2);
        alist[current_size]->SavingsStore(f1, f2);
        alist[current_size]->Project();
      } else if (!strcmp(type, type2)) {
        alist[current_size] = new Checking;
        alist[current_size]->SetName(first_name, last_name);
        alist[current_size]->SetType(type2);
        fscanf(fp, "%f", &f1);
        alist[current_size]->CheckingStore(f1);
        alist[current_size]->Project();
      } else if (!strcmp(type, type3)) {
        alist[current_size] = new Investment;
        alist[current_size]->SetName(first_name, last_name);
        alist[current_size]->SetType(type3);
        for (i = 0; i < 5; i++) {
          fscanf(fp, "%f%f%f%f", &f1, &f2, &f3, &f4);
          alist[current_size]->InvestmentStore(i, f1, f2, f3, f4);
        }
        alist[current_size]->Project();
      }
      for (i = 0; i < 50; i++) {
        if (i < 15) {
          type[i] = '\0';
        } else if (i < 25) {
          first_name[i] = '\0';
          last_name[i] = '\0';
        } else {
          input[i] = '\0';
        }
      }
      current_size++;
      fscanf(fp, "\n");
    }
    fclose(fp);
    fp = stdin;
    printf("The file is imported!\n");
    return true;
  } else {
    fp = stdin;
    printf("Invalid file. No data imported.\n");
    return false;
  }  
}
bool Portfolio::createReportFile(const char *filename) {
  fp = fopen(filename, "w");
  int hyphen = 0, i = 0;
  char chr = '-';
  const char *type1 = "Savings", *type2 = "Checking", *type3 = "Investment";
  if (fp) {
    fprintf(fp, "Banking Summary\n");
    hyphen = 25;
    while (hyphen--)
      fprintf(fp, "%c", chr);
    fprintf(fp, "\n\nSaving Accounts\n\n");
    fprintf(fp, "Holder's name                  Initial Balance  Projected Balance\n");
    hyphen = 70;
    while (hyphen--)
      fprintf(fp, "%c", chr);
    fprintf(fp, "\n");
    for (i = 0; i < current_size; i++) {
      if (!strcmp(alist[i]->getType(), type1)) {
        fprintf(fp, "%-20s %-20s %.2f      %.2f\n", 
        alist[i]->getFirstName(), alist[i]->getLastName(),
        alist[i]->getInitialBalance() + 0.005, alist[i]->getProjectedBalance() + 0.005);
      }
    }
    fprintf(fp, "\nChecking Accounts\n\n");
    fprintf(fp, "Holder's name                  Initial Balance  Projected Balance\n");
    hyphen = 70;
    while (hyphen--)
      fprintf(fp, "%c", chr);
    fprintf(fp, "\n");
    for (i = 0; i < current_size; i++) {
      if (!strcmp(alist[i]->getType(), type2)) {
        fprintf(fp, "%-20s %-20s %.2f      %.2f\n", 
        alist[i]->getFirstName(), alist[i]->getLastName(),
        alist[i]->getInitialBalance() + 0.005, alist[i]->getProjectedBalance() + 0.005);
      }
    }
    fprintf(fp, "\nInvestment Accounts\n\n");
    fprintf(fp, "Holder's name                  Initial Balance  Projected Balance\n");
    hyphen = 70;
    while (hyphen--)
      fprintf(fp, "%c", chr);
    fprintf(fp, "\n");
    for (i = 0; i < current_size; i++) {
      if (!strcmp(alist[i]->getType(), type3)) {
        fprintf(fp, "%-20s %-20s %.2f      %.2f\n", 
        alist[i]->getFirstName(), alist[i]->getLastName(),
        alist[i]->getInitialBalance() + 0.005, alist[i]->getProjectedBalance() + 0.005);
      }
    }
    fprintf(fp, "\n");
    fprintf(fp, "Overall Account distribution\n\n");
    float saving_sum = 0.000, checking_sum = 0.000, investment_sum = 0.000;
    int saving_count = 0, checking_count = 0, investment_count = 0; 
    for (i = 0; i < current_size; i++) {
      if (!strcmp(alist[i]->getType(), type1)) {
        saving_sum += alist[i]->getProjectedBalance();
        saving_count++;
      } else if (!strcmp(alist[i]->getType(), type2)) {
        checking_sum += alist[i]->getProjectedBalance();
        checking_count++;
      } else if (!strcmp(alist[i]->getType(), type3)) {
        investment_sum += alist[i]->getProjectedBalance();
        investment_count++;
      }
    }
    if (saving_count > 0)
      saving_sum /= saving_count;
    if (checking_count > 0)
      checking_sum /= checking_count;
    if (investment_count > 0)
      investment_sum /= investment_count;
    fprintf(fp, 
            "Savings:     %d     -     %.2f\n"
            "Checking:    %d     -     %.2f\n"
            "Investment:  %d     -     %.2f\n",
            saving_count, saving_sum + 0.005,
            checking_count, checking_sum + 0.005,
            investment_count, investment_sum + 0.005);
    fclose(fp);
    fp = stdin;
    printf("The file is exported!\n");
    return true;
  } else {
    fp = stdin;
    printf("Export failed!\n");
    return false;
  }
}
void Portfolio::ShowAccounts() const {
  printf("Holder                                           Type          Balance\n\n");
  for (int i = 0; i < current_size; i++) {
    printf("%-20s %-20s        %-10s    %.2f\n",
           alist[i]->getLastName(),
           alist[i]->getFirstName(),
           alist[i]->getType(),
           alist[i]->getInitialBalance() + 0.005);
  }
  printf("\n");
  return;
}