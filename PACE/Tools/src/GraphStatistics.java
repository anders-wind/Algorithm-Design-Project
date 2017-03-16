import java.util.*;
import java.io.*;

public class GraphStatistics {

	public static void main(String[] args) throws IOException {
		Set<String> vertices = new HashSet<>();
		int edges = 0;

		try (Scanner scanner = new Scanner(new File(args[0]))) {
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();

				String[] split = line.split(" ");

				vertices.add(split[0]);
				vertices.add(split[1]);

				edges++;
			}
		}

		System.out.format("Vertices: %d, edges: %d\n", vertices.size(), edges);
	}
}
