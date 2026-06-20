#include <iostream>
#include <string>
using namespace std;
string platformNames[3] = {"Instagram", "Facebook", "LinkedIn"};
double platformCharges[3] = {15000, 12000, 20000};
string clientName, businessName, businessType;
int campaignDays;
int selectedPlatform = -1;
int staticPosts, reelPosts, carouselPosts;
double adBudget;
void registerClient() {
    cout << "\n--- CLIENT REGISTRATION ---\n";
    cout << "Enter Client Name: ";
    cin.ignore();
    getline(cin, clientName);
    cout << "Enter Business Name: ";
    getline(cin, businessName);
    cout << "Business Type (1-Small, 2-Medium, 3-Corporate): ";
    int choice;
    cin >> choice;
    if (choice == 1) businessType = "Small Business";
    else if (choice == 2) businessType = "Medium Business";
    else businessType = "Corporate Business";
    cout << "Enter Campaign Duration (days): ";
    cin >> campaignDays;
}
void displayPlatforms() {
    cout << "\n--- AVAILABLE PLATFORMS ---\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". " << platformNames[i]
             << " - Base Charges: Rs. " << platformCharges[i] << "\n";
    }
}
void selectPlatform() {
    displayPlatforms();
    cout << "Select Platform (1-3): ";
    int choice;
    cin >> choice;
    if (choice >= 1 && choice <= 3) {
        selectedPlatform = choice - 1;
        cout << "Platform selected: " << platformNames[selectedPlatform] << "\n";
    } else {
        cout << "Invalid choice!\n";
    }
}
double calculatePostDesignCost() {
    cout << "\n--- POST DETAILS ---\n";
    cout << "Number of Static Posts: ";
    cin >> staticPosts;
    cout << "Number of Reel/Video Posts: ";
    cin >> reelPosts;
    cout << "Number of Carousel Posts: ";
    cin >> carouselPosts;

    double cost = (staticPosts * 1000.0) + (reelPosts * 2500.0) + (carouselPosts * 1800.0);
    return cost;
}
double calculateAdHandlingFee(double budget) {
    if (budget < 50000) return budget * 0.05;
    else if (budget <= 100000) return budget * 0.08;
    else return budget * 0.10;
}
double calculateExtraDurationCharges() {
    if (campaignDays > 30)
        return (campaignDays - 30) * 500.0;
    return 0.0;
}
double calculateGST(double amount) {
    return amount * 0.16;
}
double calculateDiscount(double amount) {
    if (businessType == "Small Business") return amount * 0.05;
    else if (businessType == "Medium Business") return amount * 0.08;
    else return amount * 0.10;
}
void displayClientDetails() {
    cout << "\n--- CLIENT DETAILS ---\n";
    cout << "Client Name    : " << clientName << "\n";
    cout << "Business Name  : " << businessName << "\n";
    cout << "Business Type  : " << businessType << "\n";
    cout << "Campaign Days  : " << campaignDays << "\n";
    if (selectedPlatform >= 0)
        cout << "Platform       : " << platformNames[selectedPlatform] << "\n";
}
void calculateCampaignCost() {
    if (selectedPlatform == -1) {
        cout << "Please select a platform first!\n";
        return;
    }
    double platformMgmt = platformCharges[selectedPlatform];
    double postCost = calculatePostDesignCost();
    cout << "Enter Ad Budget (Rs.): ";
    cin >> adBudget;
    double handlingFee = calculateAdHandlingFee(adBudget);
    double extraCharges = calculateExtraDurationCharges();
    double totalBeforeGST = platformMgmt + postCost + adBudget + handlingFee + extraCharges;
    double gst = calculateGST(totalBeforeGST);
    double totalWithGST = totalBeforeGST + gst;
    double discount = calculateDiscount(totalWithGST);
    double finalCost = totalWithGST - discount;
    cout << "\n========== SOCIAL MEDIA CAMPAIGN BILL ==========\n";
    cout << "Client Name              : " << clientName << "\n";
    cout << "Business Name            : " << businessName << "\n";
    cout << "Business Type            : " << businessType << "\n";
    cout << "Selected Platform        : " << platformNames[selectedPlatform] << "\n";
    cout << "Campaign Duration        : " << campaignDays << " Days\n\n";
    cout << "Platform Management Charges : Rs. " << platformMgmt << "\n";
    cout << "Post Design Cost            : Rs. " << postCost << "\n";
    cout << "Ad Budget                   : Rs. " << adBudget << "\n";
    cout << "Ad Handling Fee             : Rs. " << handlingFee << "\n";
    cout << "Extra Duration Charges      : Rs. " << extraCharges << "\n";
    cout << "GST (16%)                   : Rs. " << gst << "\n";
    cout << "Discount                    : Rs. " << discount << "\n";
    cout << "------------------------------------------------\n";
    cout << "Final Campaign Cost         : Rs. " << finalCost << "\n";
    cout << "================================================\n";
}
int displayMenu() {
    cout << "\n========== MAIN MENU ==========\n";
    cout << "1. View Platforms\n";
    cout << "2. Select Campaign Platform\n";
    cout << "3. Calculate Campaign Cost\n";
    cout << "4. View Client Details\n";
    cout << "5. Exit\n";
    cout << "Enter choice: ";
    int choice;
    cin >> choice;
    return choice;
}
int main() {
    registerClient();

    int choice;
    do {
        choice = displayMenu();
        switch (choice) {
            case 1: displayPlatforms(); break;
            case 2: selectPlatform(); break;
            case 3: calculateCampaignCost(); break;
            case 4: displayClientDetails(); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid option!\n";
        }
    } while (choice != 5);
    return 0;
}
