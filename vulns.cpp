#include <iostream>
#include <vector>
using namespace std;

#define print(s) (cout << s << endl)

int main()
{
  // Useful consts
  const char *criticalityStrings[4] = {"MINOR", "MODERATE", "IMPORTANT", "CRITICAL"};
  const char *impactStrings[2] = {"important", "not important"};

  // Parameters / results
  float cvss;
  char askImpact;
  unsigned short int crit;

  // CVSS score
  print("Prompt CVSS score: ");
  cin >> cvss;

  if (cvss > 10 || cvss < 0)
  {
    throw invalid_argument("CVSS score must be between 0 and 10 !");
  }

  // Is the impact high ?
  print("Is impact high ?(y/n) ");
  cin >> askImpact;

  const bool yesOrNo = (askImpact == 'y' || askImpact == 'n');

  if (!yesOrNo)
  {
    throw invalid_argument("Invalid response provided. Use only 'y' or 'n' !");
  }

  const bool impactIsHigh = (askImpact == 'y');
  const char *impactStr = (impactIsHigh) ? impactStrings[0] : impactStrings[1];
  print("User says impact is " << impactStr);

  // Determine final criticality
  crit = cvss / 3;
  if (!impactIsHigh && (crit > 0))
  {
    crit--;
  }

  print("Vulnerability is: " << criticalityStrings[crit]);
}