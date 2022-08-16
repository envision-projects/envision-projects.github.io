# [envision-projects.github.io](envision-projects.github.io)
Project and certification website for the EnVision makerspace, for use by EnVision administration

## Content Management System

This is the quickest and simplest option for writing and setting up a page. Navigate to [envision-projects.github.io/admin](envision-projects.github.io/admin) and sign in with your GitHub account. If prompted, you must give Netlify CMS permission to author commits and push on your behalf. 

After signing in, you can access the different sections of the website and view media that has been uploaded. The CMS is pretty self explanatory.

- Everything is organized into pre-defined sections; there is unfortunately not _yet_ support for nested folders. 
- Files titled `_index.md` are top level files; for example, when you click on **Mechanical** on the website, it takes you to the `_index.md` file for the mechanical section. 
- In the editor, you can either edit in WYSIWYG _"Rich Text"_ mode, or you can edit the markdown directly. 
- The preview on the right gives a basic preview of how the website will look.
- In the rich text editor, you can add links, headings, quotes, code blocks, and other elements (found under the `+` tab.)
  - For images, use the `image` element and please upload your image to the website by clicking `choose an image > upload`
  - `Tip` and `Warning` elements make your article more readable and highlight important information
  - When creating a link, use either the absolute location of the page or the relative location. For example, to link to `envision-projects.github.io/mechanical/3d-printing` the text of my link would read `/mechanical/3d-printing`. Otherwise, `3d-printing` if the file I was editing was in the same folder as the the file I was linking

When editing the page is complete, make sure that you have a title and a description (the publish date may be left as is, or set to the current time by clicking `now`). This will author a git commit with your changes and start the process of the page getting published, which should take around 5 minutes or so. 
