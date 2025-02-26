"use client";

import { Button } from "@/components/ui/button";
import { Home, Menu, X } from "lucide-react";
import Image from "next/image";
import Link from "next/link";
import { useEffect, useState } from "react";

const blogPosts = [
  {
    title: "Building Modern Web Applications",
    date: "April 15, 2024",
    excerpt:
      "Exploring the latest trends and best practices in web development...",
    slug: "building-modern-web-applications",
    readTime: "5 min",
    coverImage:
      "https://images.unsplash.com/photo-1555066931-4365d14bab8c?auto=format&fit=crop&q=80",
    author: {
      name: "Singhastra",
      avatar:
        "https://images.unsplash.com/photo-1633332755192-727a05c4013d?auto=format&fit=crop&q=80",
    },
    tags: ["Web Development", "JavaScript", "React"],
  },
  {
    title: "The Future of Frontend Development",
    date: "April 10, 2024",
    excerpt:
      "Discussing emerging technologies and frameworks that are shaping...",
    slug: "future-of-frontend-development",
    readTime: "4 min",
    coverImage:
      "https://images.unsplash.com/photo-1517694712202-14dd9538aa97?auto=format&fit=crop&q=80",
    author: {
      name: "Singhastra",
      avatar:
        "https://images.unsplash.com/photo-1633332755192-727a05c4013d?auto=format&fit=crop&q=80",
    },
    tags: ["Frontend", "JavaScript"],
  },
  {
    title: "Mastering React Hooks",
    date: "March 28, 2024",
    excerpt: "A deep dive into React Hooks and how to use them effectively...",
    slug: "mastering-react-hooks",
    readTime: "6 min",
    coverImage:
      "https://images.unsplash.com/photo-1506794778202-cad84cf45f1d?auto=format&fit=crop&q=80",
    author: {
      name: "John Doe",
      avatar:
        "https://images.unsplash.com/photo-1607748864228-8c3f08c80790?auto=format&fit=crop&q=80",
    },
    tags: ["React", "JavaScript"],
  },
  {
    title: "Understanding Asynchronous JavaScript",
    date: "March 15, 2024",
    excerpt: "Learn how async/await and promises work under the hood...",
    slug: "understanding-async-javascript",
    readTime: "7 min",
    coverImage:
      "https://images.unsplash.com/photo-1542744173-8e7e53415bb0?auto=format&fit=crop&q=80",
    author: {
      name: "Jane Smith",
      avatar:
        "https://images.unsplash.com/photo-1524504388940-b1c1722653e1?auto=format&fit=crop&q=80",
    },
    tags: ["JavaScript", "Async", "Promises"],
  },
  {
    title: "Introduction to TypeScript",
    date: "February 20, 2024",
    excerpt: "Why TypeScript is the future of JavaScript development...",
    slug: "introduction-to-typescript",
    readTime: "8 min",
    coverImage:
      "https://images.unsplash.com/photo-1517433456452-f9633a875f6f?auto=format&fit=crop&q=80",
    author: {
      name: "Alex Johnson",
      avatar:
        "https://images.unsplash.com/photo-1502767089025-6572583495b8?auto=format&fit=crop&q=80",
    },
    tags: ["TypeScript", "JavaScript"],
  },
  {
    title: "Building a Fullstack App with Node.js",
    date: "January 10, 2024",
    excerpt:
      "How to create a fullstack app using Node.js, Express, and MongoDB...",
    slug: "building-fullstack-nodejs-app",
    readTime: "10 min",
    coverImage:
      "https://images.unsplash.com/photo-1484417894907-623942c8ee29?auto=format&fit=crop&q=80",
    author: {
      name: "Chris Lee",
      avatar:
        "https://images.unsplash.com/photo-1494790108377-be9c29b29330?auto=format&fit=crop&q=80",
    },
    tags: ["Node.js", "Fullstack", "MongoDB"],
  },
  {
    title: "Deploying Web Apps with Vercel",
    date: "December 5, 2023",
    excerpt:
      "A beginner's guide to deploying web apps seamlessly using Vercel...",
    slug: "deploying-web-apps-vercel",
    readTime: "3 min",
    coverImage:
      "https://images.unsplash.com/photo-1522202176988-66273c2fd55f?auto=format&fit=crop&q=80",
    author: {
      name: "Singhastra",
      avatar:
        "https://images.unsplash.com/photo-1633332755192-727a05c4013d?auto=format&fit=crop&q=80",
    },
    tags: ["Deployment", "Vercel", "Hosting"],
  },
  {
    title: "CSS Grid vs Flexbox: When to Use Each",
    date: "November 22, 2023",
    excerpt: "A comparison of CSS Grid and Flexbox for modern layout design...",
    slug: "css-grid-vs-flexbox",
    readTime: "5 min",
    coverImage:
      "https://images.unsplash.com/photo-1512295767273-ac109ac3acfa?auto=format&fit=crop&q=80",
    author: {
      name: "Emily Roberts",
      avatar:
        "https://images.unsplash.com/photo-1534528741775-53994a69daeb?auto=format&fit=crop&q=80",
    },
    tags: ["CSS", "Grid", "Flexbox"],
  },
  {
    title: "Learning Next.js for Server-Side Rendering",
    date: "October 30, 2023",
    excerpt:
      "Exploring the benefits of using Next.js for SSR and static site generation...",
    slug: "learning-nextjs-ssr",
    readTime: "6 min",
    coverImage:
      "https://images.unsplash.com/photo-1516387938699-a93567ec168e?auto=format&fit=crop&q=80",
    author: {
      name: "Michael Green",
      avatar:
        "https://images.unsplash.com/photo-1522071820081-009f0129c71c?auto=format&fit=crop&q=80",
    },
    tags: ["Next.js", "SSR", "React"],
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
    <nav className="border rounded-md border-border/40 sticky top-5 container mx-auto bg-background/80 backdrop-blur-lg z-50">
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
    <div className="flex-1 flex gap-2 transition-all flex-wrap">
      <Button
        variant={selectedTag === null ? "default" : "outline"}
        onClick={() => onSelectTag(null)}
        className="rounded-full w-fit inline-block"
      >
        All
      </Button>
      {tags.map((tag) => (
        <Button
          key={tag}
          variant={selectedTag === tag ? "default" : "outline"}
          onClick={() => onSelectTag(tag)}
          className="rounded-full w-fit"
        >
          {tag}
        </Button>
      ))}
    </div>
  );
};

export default function BlogPage() {
  const [selectedTag, setSelectedTag] = useState<string | null>(null);
  const [isScrolled, setIsScrolled] = useState<boolean>(false);
  const filteredPosts = selectedTag
    ? blogPosts.filter((post) => post.tags.includes(selectedTag))
    : blogPosts;

  useEffect(() => {
    const handleScroll = () => {
      const scrollPosition = window.scrollY;
      setIsScrolled(scrollPosition > 3);
    };

    window.addEventListener("scroll", handleScroll);
    return () => window.removeEventListener("scroll", handleScroll);
  }, []);

  return (
    <div className="min-h-screen">
      <Navbar />
      <main
        className={
          isScrolled ? "flex " : "container mx-auto px-4 py-16 max-w-4xl"
        }
      >
        <TagFilter selectedTag={selectedTag} onSelectTag={setSelectedTag} />
        <div className="space-y-8 flex-2">
          {filteredPosts.map((post) => (
            <div
              key={post.slug}
              className="p-6 border rounded-md transition-all"
            >
              <Link href={`/blog/${post.slug}`}>
                <div className="flex gap-6">
                  <div className="relative h-32 w-48">
                    <Image
                      src={post.coverImage}
                      alt={post.title}
                      fill
                      className="object-cover rounded-md"
                    />
                  </div>
                  <div className="flex-1">
                    <h3 className="text-xl font-normal">{post.title}</h3>
                    <p className="text-muted-foreground text-sm">
                      {post.excerpt}
                    </p>
                    <div className="mt-4 flex flex-wrap gap-2">
                      {post.tags.map((tag) => (
                        <span
                          key={tag}
                          className="text-xs bg-muted rounded-full px-2 py-1"
                        >
                          {tag}
                        </span>
                      ))}
                    </div>
                  </div>
                </div>
              </Link>
            </div>
          ))}
        </div>
      </main>
    </div>
  );
}
