"use client";

import { Button } from "@/components/ui/button";
import { Calendar, Home, Menu, X } from "lucide-react";
import Image from "next/image";
import Link from "next/link";
import { useState } from "react";

const blogPosts = [
  {
    slug: "getting-started",
    title: "Getting Started with Web Development",
    excerpt: "Learn the basics of web development and start your journey.",
    date: "2024-01-01",
    readTime: "5 min read",
    coverImage:
      "https://images.unsplash.com/photo-1517433456452-f9633a875f6f?w=1200",
    author: {
      name: "John Doe",
      avatar:
        "https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=400",
    },
    tags: ["Web Development", "Beginners", "HTML", "CSS", "JavaScript"],
  },
  {
    slug: "javascript-tips",
    title: "10 JavaScript Tips You Should Know",
    excerpt: "Boost your JS skills with these essential tips and tricks.",
    date: "2024-02-10",
    readTime: "8 min read",
    coverImage:
      "https://images.unsplash.com/photo-1550745165-9bc0b252726f?w=1200",
    author: {
      name: "Jane Smith",
      avatar:
        "https://images.unsplash.com/photo-1599566150163-29194dcaad36?w=400",
    },
    tags: ["JavaScript", "Tips", "ES6", "Async/Await", "DOM Manipulation"],
  },
  {
    slug: "react-hooks",
    title: "Mastering React Hooks",
    excerpt: "Understand and use React Hooks like a pro.",
    date: "2024-03-05",
    readTime: "7 min read",
    coverImage:
      "https://images.unsplash.com/photo-1579403124614-197f69d8187b?w=1200",
    author: {
      name: "Alice Johnson",
      avatar:
        "https://images.unsplash.com/photo-1506794778202-cad84cf45f1d?w=400",
    },
    tags: ["React", "Hooks", "useState", "useEffect", "Custom Hooks"],
  },
  {
    slug: "css-tricks",
    title: "CSS Tricks for Modern Web Design",
    excerpt: "Improve your web design skills with these CSS techniques.",
    date: "2024-04-15",
    readTime: "6 min read",
    coverImage:
      "https://images.unsplash.com/photo-1512295767273-ac109ac3acfa?w=1200",
    author: {
      name: "Robert Brown",
      avatar:
        "https://images.unsplash.com/photo-1494790108377-be9c29b29330?w=400",
    },
    tags: ["CSS", "Design", "Flexbox", "Grid", "Animations"],
  },
  {
    slug: "fullstack-roadmap",
    title: "Your Roadmap to Full-Stack Development",
    excerpt: "Plan your journey from frontend to backend mastery.",
    date: "2024-05-12",
    readTime: "10 min read",
    coverImage:
      "https://images.unsplash.com/photo-1522202176988-66273c2fd55f?w=1200",
    author: {
      name: "Michael Lee",
      avatar: "https://images.unsplash.com/photo-1544005313-94ddf0286df2?w=400",
    },
    tags: ["Full-Stack", "Backend", "Frontend", "APIs", "Databases"],
  },
  {
    slug: "typescript-guide",
    title: "Understanding TypeScript for JavaScript Developers",
    excerpt: "Enhance your JS projects with TypeScript’s strong typing.",
    date: "2024-06-01",
    readTime: "7 min read",
    coverImage:
      "https://images.unsplash.com/photo-1532619187604-01988e2028f0?w=1200",
    author: {
      name: "Emily Davis",
      avatar:
        "https://images.unsplash.com/photo-1500648767791-00dcc994a43e?w=400",
    },
    tags: ["TypeScript", "JavaScript", "Static Typing", "Interfaces", "OOP"],
  },
];

const tags: string[] = [];
blogPosts.map((post) => {
  post.tags.map((tag) => {
    if (!tags.includes(tag)) {
      tags.push(tag);
    }
  });
});

const Navbar = () => {
  const [isOpen, setIsOpen] = useState(false);

  return (
    <nav className="border rounded-md border-border/40 sticky top-5 mb-10 container mx-auto bg-background/80 backdrop-blur-lg z-50">
      <div className="container mx-auto px-4 py-4">
        <div className="flex items-center justify-between">
          <Link href="/" className="flex items-center space-x-2">
            <Home className="h-6 w-6" />
            <span className="font-medium text-lg">Singhastra</span>
          </Link>

          <Button
            variant="ghost"
            size="icon"
            className="md:hidden"
            onClick={() => setIsOpen(!isOpen)}
          >
            {isOpen ? <X className="h-6 w-6" /> : <Menu className="h-6 w-6" />}
          </Button>

          <div className="hidden md:flex items-center space-x-6">
            <Link
              href="/"
              className="text-muted-foreground hover:text-foreground transition-colors"
            >
              Home
            </Link>
            <Link
              href="/blog"
              className="text-foreground font-medium border-b-2 border-primary"
            >
              Blog
            </Link>
            <Link
              href="/about"
              className="text-muted-foreground hover:text-foreground transition-colors"
            >
              About
            </Link>
          </div>
        </div>
      </div>
    </nav>
  );
};

const TagFilter = ({
  selectedTag,
  onSelectTag,
}: {
  selectedTag: string | null;
  onSelectTag: (tag: string | null) => void;
}) => {
  return (
    <div className="lg:fixed lg:top-[100px] lg:bottom-[10px] lg:max-w-[230px] bg-accent/10 w-full  p-4 rounded-lg border border-border/40 lg:mb-0 mb-6 lg:overflow-y-auto lg:max-h-[calc(100vh-110px)]">
      <div className="flex flex-row flex-wrap gap-2">
        <Button
          variant={selectedTag === null ? "default" : "outline"}
          onClick={() => onSelectTag(null)}
          className="rounded-full w-fit hover:outline-[2px] hover:outline-double hover:bg-accent/10 hover:text-white"
        >
          All
        </Button>
        {tags.map((tag) => (
          <Button
            key={tag}
            variant={selectedTag === tag ? "default" : "outline"}
            onClick={() => onSelectTag(tag)}
            className="rounded-full w-fit hover:outline-[2px] hover:outline-double hover:bg-accent/10 hover:text-white"
          >
            {tag}
          </Button>
        ))}
      </div>
    </div>
  );
};

export default function BlogPage() {
  const [selectedTag, setSelectedTag] = useState<string | null>(null);
  const filteredPosts = selectedTag
    ? blogPosts.filter((post) => post.tags.includes(selectedTag))
    : blogPosts;

  return (
    <div className="min-h-screen pb-12">
      <Navbar />
      <main className="container mx-auto px-4">
        <div className="container ">
          <TagFilter selectedTag={selectedTag} onSelectTag={setSelectedTag} />
          <div className="space-y-6 lg:ml-[250px] lg:max-w-4xl mx-auto ">
            {filteredPosts.map((post) => (
              <div
                key={post.slug}
                className="p-6 hover:outline-[2px] hover:outline-double hover:bg-accent/10  border rounded-md transition-all ease-in"
              >
                <Link key={post.slug} href={`/blog/${post.slug}`}>
                  <div className="flex gap-6">
                    <div className="relative h-32 w-48 ">
                      <Image
                        src={post.coverImage}
                        alt={post.title}
                        fill
                        className="object-cover rounded-md"
                      />
                    </div>
                    <div className="flex-1">
                      <div className="flex items-center justify-between gap-4 mb-2">
                        <h3 className="text-xl font-normal">{post.title}</h3>
                        <span className="flex items-center text-xs gap-1 text-muted-foreground tracking-wider">
                          <Calendar className="h-4 w-4" />
                          {post.date}
                        </span>
                      </div>
                      <p className="text-muted-foreground text-sm">
                        {post.excerpt}
                      </p>

                      <div className="flex items-center gap-2 mt-4">
                        <div className="relative h-8 w-8 rounded-full overflow-hidden">
                          <Image
                            src={post.author.avatar}
                            alt={post.author.name}
                            fill
                            className="object-cover"
                          />
                        </div>
                        <span className="text-sm font-normal text-muted-foreground">
                          {post.author.name}
                        </span>
                      </div>
                    </div>
                  </div>
                </Link>
              </div>
            ))}
          </div>
        </div>
      </main>
    </div>
  );
}
