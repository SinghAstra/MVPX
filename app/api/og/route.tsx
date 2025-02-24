import { siteConfig } from "@/config/site";
import { ImageResponse } from "next/og";

export const runtime = "edge";

export async function GET(req: Request) {
  const { searchParams } = new URL(req.url);
  const title = searchParams.get("title") || siteConfig.name;
  const tagline = searchParams.get("tagline") || siteConfig.tagline;

  return new ImageResponse(
    (
      <div
        style={{
          display: "flex",
          flexDirection: "column",
          justifyContent: "center",
          alignItems: "center",
          width: "1200px",
          height: "630px",
          backgroundColor: "hsl(var(--background))",
          color: "hsl(var(--foreground))",
          fontFamily: "Poppins, sans-serif",
          padding: "40px",
          border: "4px solid hsl(var(--border))",
          borderRadius: "var(--radius)",
        }}
      >
        <h1
          style={{
            fontSize: "80px",
            marginBottom: "20px",
            textAlign: "center",
            color: "hsl(var(--primary))",
          }}
        >
          {title}
        </h1>
        <p
          style={{
            fontSize: "40px",
            textAlign: "center",
            opacity: "0.8",
          }}
        >
          {tagline}
        </p>
      </div>
    ),
    {
      width: 1200,
      height: 630,
    }
  );
}
