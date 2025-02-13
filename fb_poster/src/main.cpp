#include "../include/header.h"

int main() {
  cout << "Generating prompt for image..." << endl;
  string prompt = generatePrompt(
      "Immerse yourself in an unforgettable world of adventure with a "
      "modern "
      "Stone Age family! Imagine what your life would be without modern "
      "technology—what would you do? Perhaps you would explore "
      "territories, build houses or even entire villages; farm, harvest, "
      "or maybe you would conquer new lands. You have an opportunity to "
      "be on a desert island together with the heroes of the Family "
      "Island game and try yourself in different roles: farmer, cook, "
      "explorer, trader, and many others."
      "Interested? Here are some more features of our game:"
      "★ Explore wild territories, solve puzzles, find hidden objects, and "
      "embark on thrilling adventures."
      "★ Build and improve your little city in the middle of the ocean."
      "★ Start your own family farm! Harvest, grow crops, and craft useful "
      "goods to trade with others."
      "★ Cook healthy and tasty food using ingredients found on the "
      "island."
      "★ Customize your village with beautiful decorations! Choose flowers "
      "and plants to match the unique landscapes."
      "★ Meet unusual animals: island hamsters, wild goats, and even a "
      "dinosaur are waiting for you!"
      "★ Help a family survive on a desert island."
      "And that is not all! Family Island is a farm game full of "
      "unexpected twists and captivating adventures!");
  cout << "Prompt generated successfully!" << endl;
  cout << "Generating image..." << endl;
  string img_path = generateImage(prompt);
  cout << "Image generated successfully with path : " << img_path << endl;
  cout << "Publishing to facebook..." << endl;
  string post_id = post_to_fb(img_path, FB_PAGE_ID_FAMILY_ISLAND);
  cout << "Post added with post_id : " << post_id << endl;
  // string img =
  //     generateImageFromImage("./output/test.jpg", "generate the similar
  //     image");
  // cout << "Image generated successfully at " << img << endl;

  return 0;
}
