"use client";

import { Button, buttonVariants } from "@/components/ui/button";
import { siteConfig } from "@/config/site";
import { cn } from "@/lib/utils";
import { ArrowRight, Calendar } from "lucide-react";
import Image from "next/image";
import Link from "next/link";
import { FaGithub, FaTwitter } from "react-icons/fa";

const recentPosts = [
  {
    title: "Building Modern Web Applications",
    date: "April 15, 2024",
    excerpt:
      "Exploring the latest trends and best practices in web development...",
    slug: "building-modern-web-applications",
    readTime: "5 min read",
    coverImage:
      "https://images.unsplash.com/photo-1555066931-4365d14bab8c?auto=format&fit=crop&q=80",
    author: {
      name: "Singhastra",
      avatar:
        "https://images.unsplash.com/photo-1633332755192-727a05c4013d?auto=format&fit=crop&q=80",
    },
  },
  {
    title: "The Future of Frontend Development",
    date: "April 10, 2024",
    excerpt:
      "Discussing emerging technologies and frameworks that are shaping...",
    slug: "future-of-frontend-development",
    readTime: "4 min read",
    coverImage:
      "https://images.unsplash.com/photo-1517694712202-14dd9538aa97?auto=format&fit=crop&q=80",
    author: {
      name: "Singhastra",
      avatar:
        "https://images.unsplash.com/photo-1633332755192-727a05c4013d?auto=format&fit=crop&q=80",
    },
  },
  {
    title: "Mastering TypeScript",
    date: "April 5, 2024",
    excerpt: "A comprehensive guide to using TypeScript in your projects...",
    slug: "mastering-typescript",
    readTime: "6 min read",
    coverImage:
      "https://images.unsplash.com/photo-1461749280684-dccba630e2f6?auto=format&fit=crop&q=80",
    author: {
      name: "Singhastra",
      avatar:
        "https://images.unsplash.com/photo-1633332755192-727a05c4013d?auto=format&fit=crop&q=80",
    },
  },
];

const IntroSection = () => (
  <div className="flex gap-12 items-center mb-20">
    <div className="space-y-6 flex-1">
      <div className="space-y-2">
        <h2 className="text-sm uppercase tracking-wider text-primary/60 ">
          I&apos;m{" "}
          <a
            href={siteConfig.links.github}
            target="_blank"
            className="hover:border-primary text-xl border-b border-primary/80  text-primary  "
          >
            Singhastra
          </a>
        </h2>
        <h1 className="text-4xl md:text-5xl font-bold leading-tight">
          Learning
          <br />
          & Writing about
          <br />
          <span className="text-primary/80">technologies</span>
        </h1>
      </div>
      <p className="text-lg text-muted-foreground">Full Stack Web Developer</p>
      <div className="flex gap-4">
        <Link
          href="/blogs"
          className={cn(
            buttonVariants({ variant: "default" }),
            "hover:outline-[4px] hover:outline-double transition-all ease-in"
          )}
        >
          Read Blog <ArrowRight className="ml-2 h-4 w-4" />
        </Link>
        <Link
          href="/about"
          className={cn(
            buttonVariants({ variant: "outline" }),
            "hover:outline-[4px] hover:outline-double hover:bg-transparent transition-all ease-in"
          )}
        >
          About Me
        </Link>
      </div>
    </div>
    <div className="relative h-[400px] flex-1 rounded-lg overflow-hidden border-double border-4">
      <Image
        src="https://images.unsplash.com/photo-1498050108023-c5249f4df085?auto=format&fit=crop&q=80"
        alt="Coding Environment"
        fill
        className="object-cover"
      />
      <div className="absolute inset-0 bg-gradient-to-tr from-background/80 to-transparent" />
    </div>
  </div>
);

const RecentPostsSection = () => (
  <div className="space-y-6">
    <div className="flex items-center justify-between py-6 border-b border-dotted ">
      <h2 className="text-3xl font-medium tracking-wide">Recent Posts</h2>
      <Link
        href={"/blogs"}
        className={cn(buttonVariants({ variant: "outline" }))}
      >
        View All
      </Link>
    </div>
    {recentPosts.map((post) => (
      <div
        key={post.slug}
        className="p-6  hover:outline-[6px] hover:outline-double  border rounded-md transition-all ease-in"
      >
        <Link key={post.slug} href={`/blogs/${post.slug}`}>
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
              <p className="text-muted-foreground text-sm">{post.excerpt}</p>

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
);

const FooterSection = () => (
  <footer className="border-t border-dotted pt-8">
    <div className="flex flex-col items-center text-center mb-8">
      <h2 className="text-2xl font-normal  mb-4">Let&apos;s Connect</h2>
      <p className="text-muted-foreground max-w-md mb-6">
        Join me on this journey of exploration and learning in the world of
        technology.
      </p>
      <div className="flex gap-4 mb-8">
        <Button variant="outline" size="lg" asChild className="rounded-full">
          <Link href={siteConfig.links.twitter} target="_blank">
            <FaTwitter className="h-5 w-5 mr-2" />
            Follow on Twitter
          </Link>
        </Button>
        <Button variant="outline" size="lg" asChild className="rounded-full">
          <Link href={siteConfig.links.github} target="_blank">
            <FaGithub className="h-5 w-5 mr-2" />
            Star on GitHub
          </Link>
        </Button>
      </div>
    </div>
    <div className="border-t border-dotted pt-4 text-center text-sm text-muted-foreground">
      © {new Date().getFullYear()} John Doe. All rights reserved.
    </div>
  </footer>
);

export default function Home() {
  return (
    <div className="min-h-screen">
      <div className="container mx-auto px-4 py-16 max-w-4xl flex flex-col gap-24">
        <IntroSection />
        <RecentPostsSection />

        <FooterSection />
      </div>
    </div>
  );
}
